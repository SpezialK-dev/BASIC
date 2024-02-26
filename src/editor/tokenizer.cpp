#include "tokenizer.h"
#include "../lib/string_lib.h"

int tokenizer::search_through_funktions(funktionstable* funk_table,unsigned char* input_arr){
    funktionstable table = *(funk_table);
    for(int i = 0; i< 40; ++i){
        funk_var funk = (table.getfunk_var(i));
        if(string_lib::isequal(funk.get_name(), input_arr)){
            return i;
        }
    }
    return 999;
}

int tokenizer::search_through_variables(b_var* variables_table,unsigned char* input_arr){
    for(int i=0; i<128; ++i ){
        b_var current_var= *(variables_table+i);
        //TODO implement checking equality
    }
}


void tokenizer::tokenize(funktionstable* funktable, unsigned char* input_arr,unsigned char* output, int current_linenumb){
    int line_buffer_index = 0; // at what position we are in the line buffer 
    int index{0};
    int starting_index{0};
    int ending_word_index{0};
    int saved_array_index {0};
    bool has_started=false;
    unsigned char saved_array[128];
    while(*(input_arr+index) != '\0'){
        //TODO maybe this creates a problem at the end of an array will have to check, since theoretically we could look outside of array 
        // might have some edege conition problems right here
        if(*(input_arr+index) = ' ' && *(input_arr+index+1) != '\0'  &&isalnum(*(input_arr+index+1))){
            starting_index = index;
            has_started=true;
        }
        if(has_started){
            if(*(input_arr+index) == ' '){
                saved_array[saved_array_index] = '\0';
                ending_word_index = index;
                saved_array_index = 0;
                int value_to_safe{999};
                value_to_safe = search_through_funktions(funktable, saved_array);
                if(value_to_safe != 999){
                    //TODO add syntax checking to see if next 2 variables are of needed type and save type 
                    //TODO add code that then internet skips to the next iteration to scan for the next word in the table, thus adding the next token
                    value_to_safe = value_to_safe+  16; // adds the index to where the functions start
                    *(output+line_buffer_index) = value_to_safe;
                    line_buffer_index++;

                    //TODO clean up variables to resort to last stand
                }
                //TODO add code for the variable finding!!

            }
            else{
                saved_array[saved_array_index] = *(input_arr+index);
                ++saved_array_index;
            }
        }
        ++index;
    }
}