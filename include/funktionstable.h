#ifndef funktionstable_h
#define funktionstable_h

#include "b_var.h"
#include "funk_var.h"
#include "funktions_dic.h"


class funktionstable
{
//had to switch this bc of the typedef
public:
    typedef b_var* (* funktion_sig)(int number_param,b_var* args[]);
    inline funktionstable();
  ~funktionstable();
  funk_var* getfunk_var(int index);
    funktion_sig get_funk_var_pointer(int i);
  
private:
//will have to be hardcoded here since, it should not just be assigned during initalzation but rather is aways the same
    // I sadly have to do it this way since there is no other way that currently works migth be a valid optimization at some point
    funk_var *all_funktions ;
    funktion_sig func[40]{
        // 0

    };
    //TODO add funktion array (maybe make it public???)
    //TODO make the actuall pointer array

};

funktionstable::funktionstable(){
    all_funktions = new funk_var[40];
    b_var::Types exit_sig[2]{b_var::undefined,b_var::end}; 
    unsigned char exit_name[5]{"EXIT"};
    all_funktions[0] = (funk_var{b_var::undefined,exit_sig, exit_name});
    func[0] = &funktions_dic::EXIT;

    b_var::Types let_sig[2]{b_var::undefined, b_var::end};//this might need fixing and puting stuff into some other code
    unsigned char let_name[4]{"LET"};
    all_funktions[1] = (funk_var{b_var::undefined,let_sig,let_name });//need to fix the type at some later time
    func[1] = &funktions_dic::LET;

    b_var::Types run_sig[2]{b_var::undefined,b_var::end};
    unsigned char run_name[4]{"RUN"};
    all_funktions[2] = (funk_var{b_var::integer,run_sig, run_name});
    func[2] = &funktions_dic::RUN;

    b_var::Types int_to_float_sig[2]{b_var::integer,b_var::end};
    unsigned char int_to_float_name[13]{"INT_TO_FLOAT"};
    all_funktions[3] = (funk_var{b_var::floating_p,int_to_float_sig, int_to_float_name});
    func[3] = &funktions_dic::INT_TO_FLOAT;

    b_var::Types float_to_int_sig[2]{b_var::floating_p, b_var::end};
    unsigned char float_to_int_name[13]{"FLOAT_TO_INT"};
    all_funktions[4] = (funk_var{b_var::integer,float_to_int_sig, float_to_int_name});
    func[4] = &funktions_dic::FLOAT_TO_INT;

    b_var::Types print_sig[2]{b_var::anytype,b_var::end};
    unsigned char printname[6]{"PRINT"};
    all_funktions[5] = (funk_var{b_var::undefined,print_sig, printname});
    func[5] = &funktions_dic::PRINT;
    
    b_var::Types plus_sig[3]{b_var::integer, b_var::integer,b_var::end};
    unsigned char plusname[5]{"PLUS"};
    all_funktions[6] = (funk_var{b_var::undefined,plus_sig, plusname});
    func[6] = &funktions_dic::PLUS;
    


}

#endif 
