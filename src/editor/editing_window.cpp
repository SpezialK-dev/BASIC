#include <iostream>
#include "../../include/editing_window.h"
#include "../../include/tokenizer.h"
#include "../../include/executor.h"
#include <cstring>

extern const int MAX_LINE_NUMB;

// Destructor
editing_window::~editing_window() {
  //clearing up all of the used lines 
  for(int i = 0; i<= MAX_LINE_NUMB; ++i){
      if(line_set[i]){
        delete [] linebuffer[i];
      }
    }
  delete [] linebuffer;
  
  }

bool editing_window::add_line(funktionstable* funkt_table, variable_handling* variables_table){
    int current_line;
    char c= 0;
    int index =0;
    char input_arr[256]{};
    //getting input from user 
    while(std::cin.get(c)){
        input_arr[index] = c;
        ++index;
        if(c == '\n' || index >= 122){
            break;
        }
    }
    if(index == 0){
        return false;
    }
    input_arr[index-1] = '\0';
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
        line_set[current_line] = true;
        ++last_usedline; //TODO move to add to linebuffer
    }
    delete [] outputarr;
    return true;
}
void editing_window::open_editor(funktionstable* funkt_table, variable_handling* variables_table){
    //main programm loop 
    while(currently_running){
        currently_running = add_line(funkt_table, variables_table);
    }
}
void editing_window::raise_error(int error_code){
    std::cout << "ERROR : " << error_msgs[error_code] << std::endl;
}
//breaks when encuntering the a char
int editing_window::get_line_number(char* input_line){
    unsigned long result = 0;
    char *end = input_line;
    //code to check for line numbers 
    result = std::strtoul(input_line,&end,10);
    std::memset(input_line, ' ', end-input_line);
    if(input_line == end){
        // as a fallback if no line is specified
        result = last_usedline;
    }
    // checking if 
    if(result >= MAX_LINE_NUMB){
        //TODO add a better way to deal with this error 
        result = 0;
        raise_error(3);
    }
    return static_cast<int>(result);
}
void editing_window::copy_to_line_buffer(unsigned char* input, int position){

  //free up old line to 
  if(line_set[position]){
    delete [] linebuffer[position];
  }
  line_set[position] = true;
  unsigned char* to_save =reduce_size(input);
  linebuffer[position] = to_save;
  to_save = nullptr;
}

unsigned char* editing_window::get_linebuffer_line(int line_in_linebuffer){
    if(!line_set[line_in_linebuffer]){
        return nullptr;
    }
    if(line_in_linebuffer >= MAX_LINE_NUMB){
        raise_error(3);
        return linebuffer[0];
    }
    return linebuffer[line_in_linebuffer];
}

void editing_window::end_editing_window() { currently_running = false; }

bool editing_window::get_linebuffer_bool(int current_line_bufferline) {
  return line_set[current_line_bufferline];
}

//methode to only allocate as much as needed.
//TODO move, into copy into linebuffer 

unsigned char *editing_window::reduce_size(unsigned char *input) {
  int new_lenght = 1;
  // find  out the lenght manually since there is no way to do it with strlen(a type conversion could work but would be tedious)
  while(new_lenght<255){
    if(*(input+new_lenght) == '\0' ){
      //std::cout<< "new reduced lenght" <<new_lenght << std::endl;
      ++new_lenght;
      break;
    }
    ++new_lenght;
  }
  //allocate new memory
  unsigned char * ret_value = new unsigned char[new_lenght];
  //copying the old values into the new array
  for(int i = 0; i< new_lenght;++i ){
    // prints out the index number of what is being copyied
    //creates valgrind issue of invalid read 
    //std::cout <<"input value " <<static_cast<int>(input[i]) << std::endl;
    ret_value[i] = input[i];
  }

  return ret_value;
}
