#ifndef executor_h
#define executor_h

class b_var;
#include "../editor/editing_window.h"
#include "../funktions/funktionstable.h"
#include "../variables/variable_handling.h"

class executor
{
private:
    int func_index;
    int var_index;
    int current_line;
    b_var* (* current_funcs [40])(int number_param,b_var args[]);
    b_var* *current_variables = new b_var*[120];// we will never execde 120 variables in a single line if yes we have a major problem but allocating more space is wastefull
    
public:
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