#include "funk_var.h"
#include "funktions_dic.h"

#ifndef funktionstable_h
#define funktionstable_h

class funktionstable
{
private:
    funk_var all_funktions[40];
    //TODO add funktion array (maybe make it public???)
    //TODO make the actuall pointer array
public:
    funktionstable();
    funk_var getfunk_var(int index);
    void* get_funk_var_pointer(int i);
};

//funktionstable::funktionstable(){
//    
//}

#endif 