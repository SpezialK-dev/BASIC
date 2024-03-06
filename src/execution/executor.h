#ifndef executor_h
#define executor_h

class b_var;
class executor
{
private:
    int current_line;
    b_var* *current_variables = new b_var*[120];// we will never execde 120 variables in a single line if yes we have a major problem but allocating more space is wastefull
    
public:
    inline executor();
};

executor::executor()
{
    current_line = 0;
}

#endif 