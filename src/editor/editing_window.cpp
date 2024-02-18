#include <iostream>
#include <iomanip> // needed for setw
#include "editing_window.h"


void editing_window::add_line(){
    unsigned char input_arr[256];//I include the terminator though since it is needed maybe
    std::cin >> std::setw(120) >> *input_arr ; //as specifed in atari doc 
    //TODO Add language correctness checking

    //TODO add tokenizer
    //TODO add to linebuffer
}
void editing_window::open_editor(){
    //main programm loop 
    while(currently_running){
        add_line();
    }
}
void editing_window::raise_error(int error_code){
    std::cout << "ERROR : " << error_msgs[error_code] << std::endl;
}