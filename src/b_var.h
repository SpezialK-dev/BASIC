class b_var
{
private:
    unsigned char* type = 0;
    void* pointer; 
    unsigned char name[20]{""};
public:
    b_var(unsigned char in_name[], unsigned char in_type, void* in_pointer );
    void* get_pointer();
    unsigned char get_type();
     unsigned char* get_name();
};