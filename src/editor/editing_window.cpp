#include <iostream>
#include "editing_window.h"
#include "tokenizer.h"
#include "../execution/executor.h"

void editing_window::add_line(funktionstable* funkt_table, variable_handling* variables_table){
    int current_line;
    char c= 0;
    int index =0;
    unsigned char *input_arr = new unsigned char[256];
    //getting input from user 
    while(std::cin.get(c)){
        if(c == '\n' || index >= 121){
            break;
        }
        input_arr[index] =static_cast<unsigned char>(c);
        ++index;
    }
    input_arr[index] = '\0';
    //line number stuff
    current_line = get_line_number(input_arr);
    std::cout << current_line << ": " <<input_arr << std::endl;
    
    //tokenizer stuff
    
    unsigned char *outputarr = new unsigned char[256];
    bool run_executor = false;
    run_executor = tokenizer::tokenize(funkt_table,variables_table,input_arr,outputarr,current_line);
    //if code to run the current program
    if(run_executor){
        std::cout << "RUNNING CURRENT PROGRAM" << std::endl;
        executor execution;
        execution.execute(this, funkt_table,variables_table);
        std::cout << "END RUNNING CURRENT PROGRAM" << std::endl;
    }else{

        //adding the tokenizer ouput to the final array
        copy_to_line_buffer(outputarr, current_line);
        ++last_usedline; //TODO move to add to linebuffer
    }
}
void editing_window::open_editor(funktionstable* funkt_table, variable_handling* variables_table){
    //main programm loop 
    while(currently_running){
        add_line(funkt_table, variables_table);
    }
}
void editing_window::raise_error(int error_code){
    std::cout << "ERROR : " << error_msgs[error_code] << std::endl;
}
//breaks when encuntering the a char
int editing_window::get_line_number(unsigned char* input_line){
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
    // checking if 
    if(result >= 32767){
        //TODO add a better way to deal with this error 
        result = 0;
        raise_error(3);
    }
    return result;
}
void editing_window::copy_to_line_buffer(unsigned char* input, int position){
    for(int i = 0; i< 256; ++i){
        linebuffer[position][i] = input[i];
        if(input[i] == '\0'){
            break;
        }
    }
}

unsigned char* editing_window::get_linebuffer_line(int line_in_linebuffer){
    if(line_in_linebuffer >= 32767){
        raise_error(3);
        return linebuffer[0];
    }
    return linebuffer[line_in_linebuffer];
}

void editing_window::end_editing_window(){
    currently_running = false;
}