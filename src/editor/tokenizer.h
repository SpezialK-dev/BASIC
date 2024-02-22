#include "../funktions/funktionstable.h"

#ifndef tokenizer_h
#define tokenizer_h


class tokenizer
{
private:
    int search_through_funktions(funktionstable funk_table, char* input_arr);
    int search_through_variables(funktionstable funk_table, char* input_arr);
public:
    tokenizer();
    char tokenize(char* input_arr, char* output);
};

inline tokenizer::tokenizer(/* args */)
{

}
#endif 