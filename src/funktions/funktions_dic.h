#ifndef funktions_dic_h
#define funktions_dic_h

#include "../editor/editing_window.h"
#include "../variables/variable_handling.h"
#include <iostream>


class funktions_dic
{
private:
    
public:
    b_var* EXIT(int number_param,b_var args[]);

    //maybe have to replace this with one methode
    b_var* PRINT(int number_param,b_var args[]);

    b_var* PLUS(int number_param,b_var args[]);

    b_var* MINUS(int number_param,b_var args[]);

    b_var* DIVISION(int number_param,b_var args[]);

    b_var* MULTIPLICATION(int number_param,b_var args[]);

    //conversion code
    b_var* INT_TO_FLOAT(int number_param,b_var args[]);
    b_var* FLOAT_TO_INT(int number_param,b_var args[]);

    b_var* GOTO(int number_param,b_var args[]);

    //not sure of implementation
    b_var* LET(unsigned char* input);
    //think of a way for strings
};
#endif 