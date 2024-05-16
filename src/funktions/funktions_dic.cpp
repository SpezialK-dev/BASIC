#include "../../include/funktions_dic.h"
#include <iostream>
// other stuff

b_var* funktions_dic::EXIT(int number_param,b_var* args[]){
  //just create a special b_var that returns 
  // make another way for this
  b_var* exit_bvar = new b_var();
  return exit_bvar;
}

b_var* funktions_dic::RUN(int number_param,b_var* args[]){
    //maye add some code ?? 
}

// print
//maybe replace with one function
b_var* funktions_dic::PRINT(int number_param,b_var* args[]){
    unsigned char type = (*args[0]).get_type();
    if(type == b_var::integer){
        std::cout << *(static_cast<int*>((*args[0]).get_pointer())) <<std::endl;
    }else if(type == b_var::floating_p){
        std::cout << *(static_cast<float*>((*args[0]).get_pointer())) <<std::endl;
    }else if(type == b_var::string){
        // not sure might neeed not need to dereference this its supposed to print out everything
        std::cout << *(static_cast<char*>((*args[0]).get_pointer())) <<std::endl;
    }
    return new b_var; // needed to not crash on certain CPU's since return value is needed 
}

b_var* funktions_dic::PLUS(int number_param,b_var* args[]){
    //simple precaution though should not be triggered
    if((*args[0]).get_type() != (*args[1]).get_type()){
        return new b_var;
    }
    unsigned char type = (*args[0]).get_type();
    if(type == b_var::integer){
        int return_value = *(static_cast<int*>((*args[0]).get_pointer())) + *(static_cast<int*>((*args[1]).get_pointer()));
        *(static_cast<int*>(args[1]->get_pointer())) = return_value; // allocating the value to the First one we have

    }else if(type == b_var::floating_p){
        float return_value = *(static_cast<float*>((*args[0]).get_pointer())) + *(static_cast<float*>((*args[1]).get_pointer()));
        *(static_cast<float*>(args[0]->get_pointer())) = return_value; // allocating the value to the First one we have
    }
    return new b_var;
}

b_var* funktions_dic::MINUS(int number_param,b_var* args[]){
    //simple precaution though should not be triggered
    if((*args[0]).get_type() != (*args[1]).get_type()){
        return new b_var;
;
    }
    unsigned char type = (*args[0]).get_type();
    if(type == b_var::integer){
        int return_value = *(static_cast<int*>((*args[0]).get_pointer())) - *(static_cast<int*>((*args[1]).get_pointer()));

    }else if(type == b_var::floating_p){
        float return_value = *(static_cast<float*>((*args[0]).get_pointer())) - *(static_cast<float*>((*args[1]).get_pointer()));
    }
}
b_var* funktions_dic::DIVISION(int number_param,b_var* args[]){
    //simple precaution though should not be triggered
    if((*args[0]).get_type() != (*args[1]).get_type()){
        return new b_var;
    }
    unsigned char type = (*args[0]).get_type();
    if(type == b_var::integer){
        int return_value = *(static_cast<int*>((*args[0]).get_pointer())) / *(static_cast<int*>((*args[1]).get_pointer()));

    }else if(type == b_var::integer){
        float return_value = *(static_cast<float*>((*args[0]).get_pointer())) / *(static_cast<float*>((*args[1]).get_pointer()));
    }
}

b_var* funktions_dic::MULTIPLICATION(int number_param,b_var* args[]){
    //simple precaution though should not be triggered
    if((*args[0]).get_type() != (*args[1]).get_type()){
        return new b_var;
    }
    unsigned char type = (*args[0]).get_type();
    if(type == b_var::integer){
        int return_value = *(static_cast<int*>((*args[0]).get_pointer())) * *(static_cast<int*>((*args[1]).get_pointer()));

    }else if(type == b_var::integer){
        float return_value = *(static_cast<float*>((*args[0]).get_pointer())) * *(static_cast<float*>((*args[1]).get_pointer()));
    }
}

b_var* funktions_dic::INT_TO_FLOAT(int number_param,b_var* args[]){

}

b_var* funktions_dic::FLOAT_TO_INT(int number_param,b_var* args[]){

}

b_var* funktions_dic::GOTO(int number_param,b_var* args[]){

}

b_var* funktions_dic::LET(int number_param,b_var* args[]){

}
