#include "../funktions/funktionstable.h"
#include "../variables/variable_handling.h"
#include "../variables/b_var.h"

#ifndef tokenizer_h
#define tokenizer_h


class tokenizer
{
private:
    int search_through_funktions(funktionstable funk_table, unsigned char* input_arr);
    int search_through_variables(b_var* variables_table, unsigned char* input_arr);
public:
    tokenizer(unsigned char* whole_input);
    unsigned char tokenize(unsigned char* input_arr, unsigned char* output);
};

tokenizer::tokenizer(unsigned char* whole_input)
{

}
#endif 