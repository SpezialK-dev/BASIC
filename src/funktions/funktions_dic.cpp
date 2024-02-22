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

b_var* funktions_dic::PLUS(b_var a, b_var b){
    //simple precaution though should not be triggered
    if(a.get_type() != b.get_type()){
        return new b_var;
    }
    unsigned char type = a.get_type();
    if(type == 1){
        int return_value = *(static_cast<int*>(a.get_pointer())) + *(static_cast<int*>(b.get_pointer()));

    }else if(type == 2){
        float return_value = *(static_cast<float*>(a.get_pointer())) + *(static_cast<float*>(b.get_pointer()));
    }
}

b_var* funktions_dic::MINUS(b_var a, b_var b){
    //simple precaution though should not be triggered
    if(a.get_type() != b.get_type()){
        return new b_var;
;
    }
    unsigned char type = a.get_type();
    if(type == 1){
        int return_value = *(static_cast<int*>(a.get_pointer())) - *(static_cast<int*>(b.get_pointer()));

    }else if(type == 2){
        float return_value = *(static_cast<float*>(a.get_pointer())) - *(static_cast<float*>(b.get_pointer()));
    }
}
b_var* funktions_dic::DIVISION(b_var a, b_var b){
    //simple precaution though should not be triggered
    if(a.get_type() != b.get_type()){
        return new b_var;
    }
    unsigned char type = a.get_type();
    if(type == 1){
        int return_value = *(static_cast<int*>(a.get_pointer())) / *(static_cast<int*>(b.get_pointer()));

    }else if(type == 2){
        float return_value = *(static_cast<float*>(a.get_pointer())) / *(static_cast<float*>(b.get_pointer()));
    }
}

b_var* funktions_dic::MULTIPLICATION(b_var a, b_var b){
    //simple precaution though should not be triggered
    if(a.get_type() != b.get_type()){
        return new b_var;
    }
    unsigned char type = a.get_type();
    if(type == 1){
        int return_value = *(static_cast<int*>(a.get_pointer())) * *(static_cast<int*>(b.get_pointer()));

    }else if(type == 2){
        float return_value = *(static_cast<float*>(a.get_pointer())) * *(static_cast<float*>(b.get_pointer()));
    }
}

b_var funktions_dic::INT_TO_FLOAT(b_var a){

}

b_var funktions_dic::FLOAT_TO_INT(b_var a){

}

void funktions_dic::GOTO(int line_numb){

}

void funktions_dic::LET(char* input){

}