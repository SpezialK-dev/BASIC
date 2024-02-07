#include <iostream>
#include "b_var.h"

//constructor
b_var::b_var(unsigned char in_name[], unsigned char *in_type, void* in_pointer )
{
    for(int i = 0; i< 19; ++i){
      name[i] = in_name[i];
    };
    name[20] = '\0';
    
    // 0 = undefined
    // 1 = int
    // 2 = Float
    // 3 = String
    type = in_type;
    pointer = in_pointer;
    std::cout<<"NAME: " << name <<"\n type: " << int(*type) << "\nPointer: " << &pointer;
    if(*type == 1){
        std::cout << "\nPointer Value: " << *static_cast<int*>(pointer)<<std::endl;
    }else{
        std::cout << "\nPointer Value: " << *static_cast<char*>(pointer) << std::endl;
    }
}

void* b_var::get_pointer(){
    return pointer;
}
unsigned char b_var::get_type(){
    return *type;
}
unsigned char* b_var::get_name(){
    return name;
}