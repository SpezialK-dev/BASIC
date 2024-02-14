#include "funk_var.h"

unsigned char funk_var::get_return_type(){
    return return_type;
}

char* funk_var::get_type_signature(){
    return type_signature;
}
char* funk_var::get_name(){
    return name;
}