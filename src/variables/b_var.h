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

inline b_var::b_var(unsigned char in_name[], unsigned char *in_type, void* in_pointer ){
    type = 0;
    name[0]='\0';
}