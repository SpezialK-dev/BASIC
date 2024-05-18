#include "../../include/funktionstable.h"


funk_var* funktionstable::getfunk_var(int index){
    if(index >= 40){
        return &all_funktions[0];
    }
    return &all_funktions[index];
}


funktionstable::funktion_sig funktionstable::get_funk_var_pointer(int i){
    return func[i];
}

//todo
funktionstable::~funktionstable() {
  //creates problesm currently 
  delete [] all_funktions;
  
}

 
