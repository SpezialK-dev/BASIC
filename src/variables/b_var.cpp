#include <iostream>
#include "../../include/b_var.h"

b_var::~b_var() {
  delete type;
  delete pointer;
  std::cout << "deleted variable" << name << std::endl;
  
}

void* b_var::get_pointer()const {
    return pointer;
}
unsigned char b_var::get_type()const {
    return *type;
}
unsigned char* b_var::get_name(){
    return name;
}
