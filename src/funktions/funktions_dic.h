#include "../editor/editing_window.h"
#include "../variables/b_var.h"
#include "../variables/variable_handling.h"
#include <iostream>

#ifndef funktions_dic_h
#define funktions_dic_h

class funktions_dic
{
private:
    
public:
    void EXIT(editing_window window);

    //maybe have to replace this with one methode
    void PRINT(b_var);

    b_var* PLUS(b_var a, b_var b);

    b_var* MINUS(b_var a, b_var b);

    b_var* DIVISION(b_var a, b_var b);

    b_var* MULTIPLICATION(b_var a, b_var b);

    //conversion code
    b_var* INT_TO_FLOAT(b_var a);
    b_var* FLOAT_TO_INT(b_var a);

    void GOTO(int line_numb);

    //not sure of implementation
    void LET(unsigned char* input);
    //think of a way for strings
};
#endif 