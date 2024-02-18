#include "funktions_dic.h"
// other stuff

void funktions_dic::EXIT(editing_window window){
    window.end_editing_window();
}

// print
//maybe replace with one function
void funktions_dic::PRINT(b_var a){
    unsigned char type = a.get_type();
    if(type == 1){
        std::cout << *(static_cast<int*>(a.get_pointer())) <<std::endl;
    }else if(type == 2){
        std::cout << *(static_cast<float*>(a.get_pointer())) <<std::endl;
    }else if(type == 3){
        // not sure might neeed not need to dereference this its supposed to print out everything
        std::cout << (static_cast<char*>(a.get_pointer())) <<std::endl;
    } 
}

