#ifndef funktionstable_h
#define funktionstable_h

#include "funk_var.h"
#include "funktions_dic.h"


class funktionstable
{
private:
//will have to be hardcoded here since, it should not just be assigned during initalzation but rather is aways the same
    // I sadly have to do it this way since there is no other way that currently works migth be a valid optimization at some point
    

    funk_var *all_funktions;
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
    all_funktions = new funk_var[40];
    unsigned char exit_sig[1]{0}; 
    unsigned char exit_name[5]{"EXIT"};
    all_funktions[0] = (funk_var{static_cast<unsigned char>(0),exit_sig, exit_name});
    func[0] = &funktions_dic::EXIT;
    unsigned char let_sig[1]{0};//this might need fixing and puting stuff into some other code
    unsigned char let_name[4]{"LET"};
    all_funktions[1] = (funk_var{static_cast<unsigned char>(0),let_sig,let_name });//need to fix the type at some later time
    unsigned char int_to_float_sig[1]{1};
    unsigned char int_to_float_name[13]{"INT_TO_FLOAT"};
    all_funktions[2] = (funk_var{static_cast<unsigned char>(2),int_to_float_sig, int_to_float_name});
    func[2] = &funktions_dic::INT_TO_FLOAT;
    unsigned char float_to_int_sig[1]{2};
    unsigned char float_to_int_name[13]{"FLOAT_TO_INT"};
    all_funktions[3] = (funk_var{static_cast<unsigned char>(1),float_to_int_sig, float_to_int_name});
    func[3] = &funktions_dic::FLOAT_TO_INT;
    


}

#endif 