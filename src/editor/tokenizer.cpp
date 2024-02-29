#include "tokenizer.h"
#include "../lib/string_lib.h"

int tokenizer::search_through_funktions(funktionstable* funk_table,unsigned char* input_arr){
    funktionstable table = *(funk_table);
    for(int i = 0; i< 40; ++i){
        funk_var funk = (table.getfunk_var(i));
        if(string_lib::isequal(funk.get_name(), input_arr)){
            return i+16; // is the value of starting index of where the main stuff is stored
        }
    }
    return 999;
}

int tokenizer::search_through_variables(variable_handling* variables_table,unsigned char* input_arr){
    variable_handling variable_handling_inst = *(variables_table);
    for(int i=0; i<128; ++i ){
        b_var* current_variable = variable_handling_inst.get_bvar(i);
        if(string_lib::isequal((*current_variable).get_name(),input_arr)){
            return i+128;
        }
    }
    return 999;
}


void tokenizer::tokenize(funktionstable* funktable,variable_handling* variables_table, unsigned char* input_arr,unsigned char* output, int current_linenumb){
    int line_buffer_index = 0; // at what position we are in the line buffer 
    int index{0};
    int starting_index{0};
    int ending_word_index{0};
    int saved_array_index{0};
    bool has_started=false;
    unsigned char saved_array[128];
    while(*(input_arr+index) != '\0'){
        //TODO maybe this creates a problem at the end of an array will have to check, since theoretically we could look outside of array 
        // might have some edege conition problems right here
        if(*(input_arr+index) !=' ' && *(input_arr+index+1) != '\0'  &&isalnum(*(input_arr+index+1))){
            starting_index = index;
            has_started=true;
        }
        if(has_started){
            if(*(input_arr+index) == ' ' || *(input_arr+index) == '\0' ){
                saved_array[saved_array_index] = '\0';
                ending_word_index = index;
                saved_array_index = 0;
                int value_to_safe{999};
                value_to_safe = search_through_funktions(funktable, saved_array);
                if(value_to_safe != 999){
                    std::cout << "found funktion" << value_to_safe << std::endl;
                    //TODO add syntax checking to see if next 2 variables are of needed type and save type 
                    //TODO add code that then internet skips to the next iteration to scan for the next word in the table, thus adding the next token
                    *(output+line_buffer_index) = value_to_safe;
                    line_buffer_index++;

                    //cleaning up variables
                    starting_index = ending_word_index;
                    has_started = false;
                    continue;//skip
                }
                //code snippet for variable stuff
                value_to_safe = search_through_variables(variables_table,saved_array);
                if(value_to_safe != 999){
                    *(output+line_buffer_index) = value_to_safe;
                    line_buffer_index++;

                    //cleaning up variables
                    starting_index = ending_word_index;
                    has_started = false;
                    continue;//skip
                }
                //If there is no variable we should create one should add a catch statment if it does not fit into the variable roster 
                
            }
            else{
                saved_array[saved_array_index] = *(input_arr+index);
                ++saved_array_index;
            }
        }
        ++index;
    }
}