#include "tokenizer.h"
#include "../lib/string_lib.h"


int tokenizer::search_through_funktions(funktionstable funk_table,unsigned char* input_arr){
    for(int i = 0; i< 40; ++i){
        funk_var funk = funk_table.getfunk_var(i);
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


unsigned char tokenizer::tokenize(unsigned char* input_arr,unsigned char* output){
    
}