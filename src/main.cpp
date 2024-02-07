#include <iostream>
#include <iomanip> // needed for setw
#include "variable_handling.h"

//can get a max of 255 bytes of input so 255 char array?
//for now I will use this since, this is the amount of Chars that where possible in atari basic
void get_Input(){
    unsigned char input_arr[256];//I include the terminator though since it is needed maybe
    std::cin >> std::setw(120) >> *input_arr ; //as specifed in atari doc 
    //TODO Add language correctness checking
    
}

int main(){
    
  //std::cout << "hello World" << std::endl;
    
    // temp code
    variable_handling v;
    unsigned char test[20]{"Hello World"};
    unsigned char test2[20]{"Goodbye World"};
    unsigned char test_v[10]{"123"};
    v.create_new_variable(test,test_v);
    v.create_new_variable(test2,test);
    //testing return values
    unsigned char* return_test;
    unsigned char* return_test2;
    int* return_var_test;
    //return_test =  v.get_variable_name(0);
    //return_test2 =v.get_variable_name(1);
    //return_var_test = static_cast<int*>(v.get_value(0));
    //std::cout << return_test << "::"<< *return_var_test <<"," << return_test2 << std::endl;
    
    // testing delete Statment
    //v.delete_variabel(0);
    //return_test = v.get_variable_name(0);
    //std::cout << return_test << std::endl;
}

