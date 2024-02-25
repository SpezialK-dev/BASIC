#ifndef tokenizer_h
#define tokenizer_h

#include "../funktions/funktionstable.h"
#include "../variables/variable_handling.h"
#include "../variables/b_var.h"


class tokenizer
{
private:
    static int search_through_funktions(funktionstable* funk_table, unsigned char* input_arr);
    static int search_through_variables(b_var* variables_table, unsigned char* input_arr);
public:
    tokenizer(unsigned char* whole_input);
    static unsigned char tokenize(funktionstable* funktable, unsigned char* input_arr, unsigned char* output, int current_linenumb);
};

tokenizer::tokenizer(unsigned char* whole_input)
{

}
#endif 