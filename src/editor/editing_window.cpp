#include <iostream>
#include "editing_window.h"
#include <ctype.h>

void editing_window::add_line(){
    int current_line;
    char c= 0;
    int index =0;
    char input_arr[256];
    while(std::cin.get(c)){
        if(c == '\n' || index >= 121){
            break;
        }
        input_arr[index] = c;
        ++index;
    }
    input_arr[index] = '\0';
    current_line = get_line_number(input_arr);
    std::cout << current_line << " : " <<input_arr << std::endl;
    
    
    
    //TODO Add language correctness checking
 
    //TODO add tokenizer

    //TODO add to linebuffer
    ++last_usedline; //TODO move to add to linebuffer
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


//breaks when encuntering the a char or an empty space
int editing_window::get_line_number(char* input_line){
    int i = 0;
    int result = 0;
    //code to check for line numbers 
    while(i< 128){
        if(std::isalpha(input_line[i])){
            break;
        }
        if(std::isdigit(input_line[i])){
            result = result * 10 + (input_line[i]-'0');
            input_line[i] = ' ';//todo make a more proper fix out of this
        }
        i++;
    }
    if(result == 0){
        // as a fallback if no line is specified
        result = last_usedline;
    }
    return result;
}