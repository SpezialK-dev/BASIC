
#ifndef variable_handling_h
#define variable_handling_h

#include "b_var.h"

class variable_handling
{
private:
    
    b_var* *variables  = new b_var*[128];
    unsigned char find_space_in_variable(unsigned char *name);
    unsigned char last_elem = 0; 
public:
    void create_new_variable(unsigned char  name[], unsigned char value[]);
    unsigned char* get_variable_name(unsigned char token);
    void* get_value(unsigned char token);
    void delete_variabel(unsigned char token);
    b_var* get_bvar(int index);
};
#endif 