#ifndef b_var_h
#define b_var_h

class b_var
{
private:
    unsigned char* type;
    void* pointer; 
    unsigned char name[20]{""};
public:
    b_var(unsigned char in_name[], unsigned char *in_type, void* in_pointer );
    void* get_pointer();
    unsigned char get_type();
    unsigned char* get_name();
};

//constructor
b_var::b_var(unsigned char in_name[], unsigned char *in_type, void* in_pointer )
{
    for(int i = 0; i< 19; ++i){
      name[i] = in_name[i];
    };
    name[20] = '\0';
    
    // 0 = undefined
    // 1 = int
    // 2 = Float
    // 3 = String
    type = in_type;
    pointer = in_pointer;
}

#endif /* b_var_h */