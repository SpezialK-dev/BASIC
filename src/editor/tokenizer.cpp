#include "../../include/tokenizer.h"
#include "../../include/string_lib.h"
#include <cctype>

tokenizer::tokenizer(unsigned char* whole_input)
{

}


int tokenizer::search_through_funktions(funktionstable* funk_table,unsigned char* input_arr){
    for(int i = 0; i< 40; ++i){
      funk_var* funk = (funk_table->getfunk_var(i));
        bool result= string_lib::isequal((*funk).get_name(), input_arr);
        if(result){
            return i+16; // is the value of starting index of where the main stuff is stored
        }
    }
    return 999;
}

int tokenizer::search_through_variables(variable_handling* variables_table,unsigned char* input_arr){
  
    //checking if the array is empty to check cause otherwies we will segfault
    if((*variables_table).get_last_elem() == 255){
        return 999;
    }
    int max_vars = (*variables_table).get_last_elem();
    for(int i=0; i<max_vars; ++i ){
        b_var* current_variable = variables_table->get_bvar(i);
        if(string_lib::isequal(current_variable->get_name(),input_arr)){
            return i+128;
        }
    }
    return 999;
}



bool tokenizer::tokenize(funktionstable* funktable,variable_handling* variables_table, char* input_arr,unsigned char* output, int current_linenumb){
    int line_buffer_index{0}; // at what position we are in the line buffer 
    int variable_index{0};
    int output_buffer_index{0};
    int index{0};
    int starting_index{0};
    int ending_word_index{0};
    int saved_array_index{0};
    bool has_started_bool=false;
    bool variable_found_bool =false;
    bool variable_name_bool = true;
    bool variable_value_bool = false;
    bool variable_finished = false;
    bool variabel_value_started_bool = false; //needed to skip the first ' ' if needed
    bool running = true;
    unsigned char *saved_array = new unsigned char[128];
    unsigned char *variable_name = new unsigned char[20];
    unsigned char *variabl_value = new unsigned char[30];
    while(running){
      if(isalnum(*(input_arr+index))){
            starting_index = index;
            has_started_bool=true;
        }
        if(has_started_bool){
            if(*(input_arr+index) == ' ' || *(input_arr+index) == '\0' ){
                saved_array[saved_array_index] = '\0';
                ending_word_index = index;
                saved_array_index = 0;
                int value_to_safe{999};
                value_to_safe = search_through_funktions(funktable, saved_array);
                if(value_to_safe == 17){
                    //TODO add code to create funktions
                    variable_found_bool = true;
                    has_started_bool = false;
                }
                // run code
                if(value_to_safe == 18){
                    //TODO add code to create funktions
                    variable_found_bool = true;
                    has_started_bool = false;
                    return true;
                }
                
                if(value_to_safe != 999 && value_to_safe != 17 && value_to_safe != 18){//exclude 17 because its the let funktion
                    //std::cout << "found funktion" << value_to_safe << std::endl;
                    //TODO add syntax checking to see if next 2 variables are of needed type and save type 
                    //TODO add code that then internet skips to the next iteration to scan for the next word in the table, thus adding the next token
                    *(output+output_buffer_index) = value_to_safe;
                    output_buffer_index++;
                    line_buffer_index++;

                    //cleaning up variables
                    starting_index = ending_word_index;
                    has_started_bool = false;
                    continue;
                    
                }
                //code snippet for variable stuff
                value_to_safe = search_through_variables(variables_table,saved_array);
                if(value_to_safe != 999){
                    *(output+output_buffer_index) = value_to_safe;
                    output_buffer_index++;
                    line_buffer_index++;

                    //cleaning up variables
                    starting_index = ending_word_index;
                    has_started_bool = false;
                    continue;//skip
                }
                //If there is no variable we should create one should add a catch statment if it does not fit into the variable roster 
                
            }
            else{
                saved_array[saved_array_index] = *(input_arr+index);
                ++saved_array_index;
            }
        }
        //my attempt at fixing just a word without empty space afterwards
        if(variable_found_bool){
            //code for getting the variable name into an array
            if(variable_name_bool){
                //should break if we get the = sign since that is the part where the value starts
                if(*(input_arr+index) == '=' || variable_index > 19 ){
                    variable_name[variable_index] = '\0'; // this is hardcoded since there should not be a other value needs to be changed if name is longer
                    variable_name_bool = false;
                    variable_value_bool = true;
                    variable_index = 0;
                }
                //code that adds part of the name that adds to the name array, also it ignores whitespaces
                if(*(input_arr+index) != ' ' && variable_value_bool == false){
                    variable_name[variable_index] = *(input_arr+index);
                    variable_index++;
                }
            }
            //code for finding the value the value
            if(variable_value_bool){
                if(isalnum(*(input_arr+index))){
                    variabel_value_started_bool = true;
                }
                if(variabel_value_started_bool){
                    //since the value has started, we will end at the last 
                    if(*(input_arr+index) == ' ' || variable_index == 29 || *(input_arr+index) == '\0'){//TODO add == to ' " 'since we stuff for arrays does not work
                        variabl_value[29] = '\0';
                        variable_finished = true;
                    }
                    variabl_value[variable_index] = *(input_arr+index);
                    variable_index++;
                }
            }
            if(variable_finished){
                //reseting all the variables 
                bool variable_found_bool =false;
                bool variable_name_bool = true;
                bool variable_value_bool = false;
                bool variable_finished = false;
                bool variabel_value_started_bool = false;
                //TODO Clean the arrays.

                (*variables_table).create_new_variable(variable_name,variabl_value);
            }
        }
        //safty check
        if(*(input_arr+index) == '\0' || index == 119 ){
            running = false;
            output[output_buffer_index] = '\0';
        }
        ++index;
        
    }
    delete [] saved_array;
    delete [] variable_name;
    delete [] variabl_value;
    return false;
    
}
