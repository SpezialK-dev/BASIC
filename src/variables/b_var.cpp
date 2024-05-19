
#include "../../include/b_var.h"

b_var::~b_var() { delete pointer; }
b_var::b_var(void * in_pointer):pointer{in_pointer} {}

void* b_var::get_pointer()const {
    return pointer;
}
b_var::Types b_var::get_type()const {
    return type;
}
unsigned char* b_var::get_name(){
    return name;
}
