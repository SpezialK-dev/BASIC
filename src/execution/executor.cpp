#include "../../include/executor.h"
#include "../../include/string_lib.h"
#include <iterator>

executor::~executor() {
  delete[] current_variables;
}

void executor::execute(editing_window *window, funktionstable* funktable,variable_handling* variables_table){
    bool running =true;
    while(running){
        unsigned char *current_line_buffer = window->get_linebuffer_line(current_line);
        for(int i = 0;current_line_buffer != nullptr && i< 120; ++i){
            //code to loading the current line into the buffers
            if(current_line_buffer[i] == '\0'){
                break;
            }
            //funktion check
            //empty space from 56 till 127 since that is the space not in use rn.
            if(current_line_buffer[i] >= 16 && current_line_buffer[i] < 56 ){
                //getting the current funktion and putting it into the stack of saved funktions that we are currently using
                current_funcs[func_index] = static_cast<funktionstable::funktion_sig>((*funktable).get_funk_var_pointer((current_line_buffer[i] -16)));
                current_funcs_names[func_index] = static_cast<funk_var*>((*funktable).getfunk_var( (current_line_buffer[i] -16) ));
                ++func_index;
                //TODO add limit for max of 40 funktions per line which should never be hit lol
            }
            //variable code 
            //255 should be the max number if I remeber correctly, will have to check again through
            if(current_line_buffer[i] >= 128 && current_line_buffer[i] < 255 ){
                current_variables[var_index] = (*variables_table).get_bvar(current_line_buffer[i] -128);
                var_index++;
            }
	    
        }
        //EXECUTION CODE!!
        //code for getting through the funktion array
        for(int i = 0; current_line_buffer != nullptr && i< 120; ++i){ //TODO check if 120 is enought not sure yet
            //if we have a funktion to run run it
            //std::cout << "i : "<< i << " funk_index : "<< func_index << std::endl;
            if(func_index != 0){
	      
	      //reimplemented a way to get the ammount of variables needed
	      int param_count = 0;
	      b_var::Types* current_types = current_funcs_names[i]->get_type_signature();
	      for(int i = 0; i< 10; ++i ){
		if(*(current_types+i) == b_var::end){
		  break;
		}
		++param_count;
	      }
	      
                b_var* *variables_to_give_to_func = new b_var* [10];
                //putting the variables into the current funktion and then exeucint that value
                for(int param_loop = 0; param_loop< param_count; param_loop++){
                    //TODO add some safty checks to not go out of index
                    int value_to_access = var_index - (param_loop+1); //we want to get to top value of the stack and then put that into our funktion
                    variables_to_give_to_func[param_loop] = current_variables[value_to_access];//copying the value into 
                }
		//exeuction
               b_var* funk_return  = current_funcs[i](param_count,variables_to_give_to_func );
	       
                // clean up code 
	       delete funk_return; //temp fix will later be be better implemented 
	       current_funcs[func_index] = nullptr;
                current_funcs_names[func_index] = nullptr;
                --func_index;

            }
            
            if(func_index == 0){
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
