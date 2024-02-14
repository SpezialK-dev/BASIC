#include <iostream>
#include <iomanip> // needed for setw

//moved here from main, will be implemented later.
void get_Input(){
    unsigned char input_arr[256];//I include the terminator though since it is needed maybe
    std::cin >> std::setw(120) >> *input_arr ; //as specifed in atari doc 
    //TODO Add language correctness checking
    
}