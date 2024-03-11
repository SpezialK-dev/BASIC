#include "executor.h"

void executor::execute(editing_window *window){
    bool running =true;
    while(running){
        for(int i = 0; i< 120; ++i){
            //code to loading the current line into the buffers
            if(*((*window).get_linebuffer_line(current_line)+i) == '\0'){
                break;
            }
            //funktion check
            if(*((*window).get_linebuffer_line(current_line)+i) >= 16&& *((*window).get_linebuffer_line(current_line)+i) <= 127 ){

            }
        }
        //code for getting through the funktion array
        for(int i = 0; i< 120; ++i){ //TODO check if 120 is enought not sure yet
            
        }

        ++current_line;
    }
}