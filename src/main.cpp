#include <iostream>
#include <iomanip> // needed for setw

//can get a max of 255 bytes of input so 255 char array?
//for now I will use this since, this is the amount of Chars that where possible in atari basic
void get_Input(){
    char input_arr[256];//I include the terminator though since it is needed maybe
    std::cin >> std::setw(120) >> *input_arr ; //as specifed in atari doc 
    //TODO Add language correctness checking
    
}

int main(){
    std::cout << "hello World" << std::endl;
}

