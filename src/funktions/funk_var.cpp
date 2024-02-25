#include "funk_var.h"

unsigned char funk_var::get_return_type(){
    return return_type;
}

unsigned char* funk_var::get_type_signature(){
    return type_signature;
}
unsigned char* funk_var::get_name(){
    return name;
}
void funk_var::copy_array(int lenght,unsigned char* to_copy_to,unsigned char* copy_from){
    for(int i = 0; i < lenght; ++i){
        *(to_copy_to+i) = *(to_copy_to+i);
    }
}
