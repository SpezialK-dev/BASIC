#ifndef funk_var_h
#define funk_var_h

#include "b_var.h"
class funk_var

    {
private:
      b_var::Types return_type;
      b_var::Types type_signature[10]{b_var::undefined,b_var::end};
    unsigned char name[25]{"N"};
    void copy_array(int lenght,unsigned char* to_copy_to,unsigned char* copy_from);
public:
      inline funk_var(b_var::Types return_type,
		      b_var::Types type_signature[],unsigned char* inp_name
            );
    inline funk_var();
      b_var::Types get_return_type();
      b_var::Types* get_type_signature();
    unsigned char* get_name();
       
};
//this requires the arrays to be the same size!!
//but it should not matter in the context of this class!

funk_var::funk_var(b_var::Types inp_return_type,b_var::Types inp_type_signature[],unsigned char* inp_name){
    return_type = inp_return_type;
    for(int i = 0; i< 10; i++ ){
      type_signature[i] = inp_type_signature[i];
    }

    copy_array(25, name, inp_name);
}

funk_var::funk_var(){
  return_type = b_var::undefined;
    for(int i = 0; i< 10 ; i++){
        type_signature[i] = b_var::undefined;
    }
    
    
}
#endif 
