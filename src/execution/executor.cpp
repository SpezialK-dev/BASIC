#include "executor.h"

void executor::execute(editing_window *window, funktionstable* funktable,variable_handling* variables_table){
    bool running =true;
    while(running){
        for(int i = 0; i< 120; ++i){
            //code to loading the current line into the buffers
            if(*((*window).get_linebuffer_line(current_line)+i) == '\0'){
                break;
            }
            //funktion check
            //empty space from 56 till 127 since that is the space not in use rn.
            if(*((*window).get_linebuffer_line(current_line)+i) >= 16 && *((*window).get_linebuffer_line(current_line)+i) < 56 ){
                //getting the current funktion and putting it into the stack of saved funktions that we are currently using
                current_funcs[func_index] = static_cast<funktionstable::funktion_sig>((*funktable).get_funk_var_pointer((*((*window).get_linebuffer_line(current_line)+i) -16)));
                
                ++func_index;
                //TODO add limit for max of 40 funktions per line which should never be hit lol
            }
            //variable code 
            //255 should be the max number if I remeber correctly, will have to check again through
            if(*((*window).get_linebuffer_line(current_line)+i) >= 128 && *((*window).get_linebuffer_line(current_line)+i) < 255 ){
                current_variables[var_index] = (*variables_table).get_bvar(*((*window).get_linebuffer_line(current_line)+i) -128);
                var_index++;
            }
        }
        //code for getting through the funktion array
        for(int i = 0; i< 120; ++i){ //TODO check if 120 is enought not sure yet
            //if we have a funktion to run run it
            if(func_index != 0){
                
            }
        }

        ++current_line;
    }
}
