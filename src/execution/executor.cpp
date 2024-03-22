#include "executor.h"
#include "../lib/string_lib.h"


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
                current_funcs_names[func_index] = static_cast<funk_var*>((*funktable).getfunk_var( (*((*window).get_linebuffer_line(current_line)+i) -16) ));
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
        //EXECUTION CODE!!
        //code for getting through the funktion array
        for(int i = 0; i< 120; ++i){ //TODO check if 120 is enought not sure yet
            //if we have a funktion to run run it
            if(func_index != 0){
                int param_count = string_lib::uns_strlen((*current_funcs_names[i]).get_type_signature());
                b_var* *variables_to_give_to_func = new b_var* [10];
                //putting the variables into the current funktion and then exeucint that value
                for(int i = 0; i< param_count; i++){
                    //TODO add some safty checks to not go out of index
                    int value_to_access = var_index - (i+1); //we want to get to top value of the stack and then put that into our funktion
                    variables_to_give_to_func[i] = current_variables[value_to_access];//copying the value into 
                }
                *current_funcs[i](param_count,variables_to_give_to_func );
            }
            if(func_index == i){
                break;
            }
        }
        //just a safty precaution
        if(current_line == 32766){
            break;
        }
        ++current_line;
    }
}
