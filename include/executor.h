#ifndef executor_h
#define executor_h

class b_var;
#include "editing_window.h"
#include "funktionstable.h"
#include "variable_handling.h"


class executor
{
private:
    int func_index;
    int var_index;
    int current_line;
    funktionstable::funktion_sig current_funcs [40];
    funk_var* current_funcs_names[40];
    b_var* *current_variables = new b_var*[120];// we will never execde 120 variables in a single line if yes we have a major problem but allocating more space is wastefull

public:
  ~executor();
  inline executor();
  void execute(editing_window *window, funktionstable* funktable,variable_handling* variables_table);
};

executor::executor()
{
    current_line = 0;
    func_index = 0;
    var_index = 0;
}

#endif 
