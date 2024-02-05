#include <iostream>
#include <iomanip> // needed for setw
#include "varianle_handling.h"


//can get a max of 255 bytes of input so 255 char array?
//for now I will use this since, this is the amount of Chars that where possible in atari basic
void get_Input(){
    char input_arr[256];//I include the terminator though since it is needed maybe
    std::cin >> std::setw(120) >> *input_arr ; //as specifed in atari doc 
    //TODO Add language correctness checking
    
}

int main(){
    
    //std::cout << "hello World" << std::endl;
    
    // temp code
    variable_handling v;
    char test[20]{'H','E','L','L','O',' ','W','O','R','L','D'};
    v.create_new_variable(test, test);
    char return_test;
    return_test =  v.get_variable_name(1);
    std::cout << return_test << std::endl;
}

