class funk_var
{
private:
    unsigned char return_type;
    char type_signature[10];
    char name[25];
public:
    funk_var(unsigned char return_type,
            char type_signature[], char name[]
            );
    unsigned char get_return_type();
    char* get_type_signature();
    char* get_name();
       
};
//this requires the arrays to be the same size!!
//but it should not matter in the context of this class!
inline void copy_array(int lenght, char* to_copy_to, char* copy_from){
    for(int i = 0; i < lenght; ++i){
        *(to_copy_to+i) = *(to_copy_to+i);
    }
}

inline funk_var::funk_var(unsigned char inp_return_type, char inp_type_signature[], char inp_name[]){
    return_type = inp_return_type;
    copy_array(10, type_signature, inp_type_signature);
    copy_array(25, name, inp_name);
}