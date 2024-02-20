#include "string_lib.h"
#include <cstring>

int string_lib::search_for_substring(char* search_in, char* what_to_search_for){
    int return_value = 999; //though could be bigger in future
    // to not waste cpu performance since the search is impossible
    if(strlen(what_to_search_for) > strlen(search_in) ){
       return 0;//return max int or smt 
    }
    //main search loop
    for(int i = 0;i < strlen(search_in); i++){
        if(search_in[i] == '\0'){
            break;//TODO ADD RETURN
        }
        //if match found
        if(search_in[i] == what_to_search_for[0]){
            int temp_index = i;
            for(int j = 0;j < strlen(what_to_search_for); ++j ){
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

bool string_lib::isequal(char* a, char* b){
    int i = 0;
    while(*(a+i)  != '\0' && *(b+i) != '\0'){
        if(*(a+i) != *(b+i)){
            return false;
        }
        ++i; 
    }
}