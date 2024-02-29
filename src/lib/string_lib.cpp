#include "string_lib.h"
#include <iostream>



int string_lib::search_for_substring(unsigned char* search_in,unsigned char* what_to_search_for){
    int return_value = 999; //though could be bigger in future
    // to not waste cpu performance since the search is impossible
    if(uns_strlen(what_to_search_for) > uns_strlen(search_in) ){
       return 0;//return max int or smt 
    }
    //main search loop
    for(int i = 0;i < uns_strlen(search_in); i++){
        if(search_in[i] == '\0'){
            break;//TODO ADD RETURN
        }
        //if match found
        if(search_in[i] == what_to_search_for[0]){
            int temp_index = i;
            for(int j = 0;j < uns_strlen(what_to_search_for); ++j ){
                //when to return to the main loop
                if (search_in[i+j] == '\0' || search_in[i+j] != what_to_search_for[j]){
                    break;
                }
                //we went through everything and everything matched since no missmatch happend so we return the starting value that we found
                if(what_to_search_for[j] == '\0'){
                    return temp_index;
                }
            }
        }
    }
    
    return return_value;
}

bool string_lib::isequal(unsigned char* a,unsigned char* b){
    int i = 0;
    //TODO add check to see if none of the arrays are empty to prevent crash from happening !!^
    while(*(a+i)  != '\0' || *(b+i) != '\0'){
        if(*(a+i) != *(b+i)){
            return false;
        }
        
        ++i; 
        //temp bandaid works but IG 
        if(*(a+i)  == '\0' && *(b+i) == '\0'){
            return true;
        }

        if(*(a+i)  == '\0' || *(b+i) == '\0'){
            break;
        }
    }
}

int string_lib::uns_strlen(unsigned char* input_arr){
    int counter =0;
    while(*(input_arr+counter) != '\0'){
        ++counter;
    }
    return counter;
}