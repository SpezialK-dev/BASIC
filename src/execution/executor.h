#ifndef executor_h
#define executor_h

class executor
{
private:
    int current_line;
public:
    inline executor();
};

executor::executor()
{
    current_line = 0;
}

#endif 