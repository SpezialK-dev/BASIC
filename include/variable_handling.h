
#ifndef variable_handling_h
#define variable_handling_h

#include "b_var.h"

class variable_handling
{
private:
    
    b_var* *variables  = new b_var*[128];
  bool var_pop[128];//default false
  unsigned char last_elem{255}; 
    unsigned char find_space_in_variable(unsigned char *name);
public:
   variable_handling();
   ~variable_handling();

  void create_new_variable(unsigned char  *name, unsigned char *value);
    unsigned char* get_variable_name(unsigned char token);
    void* get_value(unsigned char token);
    void delete_variabel(unsigned char token);
  b_var* get_bvar(int index){
    return variables[index];
  }
    unsigned char get_last_elem(){
      return last_elem;
    }

};

#endif 
