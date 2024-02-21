#include <iostream>
#include "b_var.h"


void* b_var::get_pointer(){
    return pointer;
}
unsigned char b_var::get_type(){
    return *type;
}
unsigned char* b_var::get_name(){
    return name;
}