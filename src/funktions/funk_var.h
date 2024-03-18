#ifndef funk_var_h
#define funk_var_h

class funk_var
{
private:
    unsigned char return_type;
    unsigned char *type_signature = new unsigned char[10];
    unsigned char name[25]{"N"};
    void copy_array(int lenght,unsigned char* to_copy_to,unsigned char* copy_from);
public:
    inline funk_var(unsigned char return_type,
            unsigned char type_signature[],unsigned char* inp_name
            );
    inline funk_var();
    unsigned char get_return_type();
    unsigned char* get_type_signature();
    unsigned char* get_name();
       
};
//this requires the arrays to be the same size!!
//but it should not matter in the context of this class!

funk_var::funk_var(unsigned char inp_return_type,unsigned char inp_type_signature[],unsigned char* inp_name){
    return_type = inp_return_type;
    copy_array(10, type_signature, inp_type_signature);

    copy_array(25, name, inp_name);
}

funk_var::funk_var(){
    return_type = 0;
    type_signature[0] = 0;
    type_signature[9] = '\0';
}
#endif 