#ifndef string_lib_h
#define string_lib_h

class string_lib
{
private:
    
public:
   static int search_for_substring(unsigned char* search_in,unsigned char* what_to_search_for);
   static bool isequal(unsigned char* a,unsigned char* b);
   static int uns_strlen(unsigned char* input_arr);
};

#endif