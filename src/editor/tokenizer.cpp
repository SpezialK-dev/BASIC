#include "tokenizer.h"
#include "../lib/string_lib.h"


int tokenizer::search_through_funktions(funktionstable funk_table, char* input_arr){
    for(int i = 0; i< 40; ++i){
        funk_var funk = funk_table.getfunk_var(i);
        if(string_lib::isequal(funk.get_name(), input_arr)){
            return i;
        }
    }
    return 999;
}

int tokenizer::search_through_variables(funktionstable funk_table, char* input_arr){

}


char tokenizer::tokenize(char* input_arr, char* output){
    
}