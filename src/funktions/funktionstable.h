#ifndef funktionstable_h
#define funktionstable_h

#include "funk_var.h"
#include "funktions_dic.h"


class funktionstable
{
private:
//will have to be hardcoded here since, it should not just be assigned during initalzation but rather is aways the same
    // I sadly have to do it this way since there is no other way that currently works migth be a valid optimization at some point
    

    funk_var all_funktions[40];
    b_var* (* func [40])(int number_param,b_var args[]){
        // 0

    };
    //TODO add funktion array (maybe make it public???)
    //TODO make the actuall pointer array
public:
    inline funktionstable();
    funk_var getfunk_var(int index);
    void* get_funk_var_pointer(int i);
};

funktionstable::funktionstable(){
    unsigned char exit_sig[1]{0}; 
    unsigned char exit_name[5]{"EXIT"};
    all_funktions[0] = (funk_var{static_cast<unsigned char>(0),exit_sig, exit_name});
}

#endif 