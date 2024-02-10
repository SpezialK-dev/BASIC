class funk_var
{
private:
    void* funtion_pointer;
    unsigned char return_type;
    char type_signature[10];
    char name[25];
public:
    funk_var(void* func_pointer, unsigned char return_type,
            char type_signature[], char name[]
            );
    void* get_func();
    unsigned char get_return_type();
    char* get_type_signature();
    char* get_name();
       
};