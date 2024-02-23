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