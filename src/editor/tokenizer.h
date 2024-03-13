#ifndef tokenizer_h
#define tokenizer_h

#include "../funktions/funktionstable.h"
#include "../variables/variable_handling.h"
#include "editing_window.h"


class tokenizer
{
private:
    static int search_through_funktions(funktionstable* funk_table, unsigned char* input_arr);
    static int search_through_variables(variable_handling* variables_table, unsigned char* input_arr);
public:
    inline tokenizer(unsigned char* whole_input);
    static bool tokenize(funktionstable* funktable,variable_handling* variables_table, unsigned char* input_arr, unsigned char* output, int current_linenumb);
};

tokenizer::tokenizer(unsigned char* whole_input)
{

}
#endif 