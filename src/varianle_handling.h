class variable_handling
{
private:
    char variable_names[128][21]={""};
    void* value_array[128]; 
    char find_space_in_variable(char *name);
    char last_elem = 0; 
public:
    void create_new_variable(char  name[], char value[]);
    char& get_variable_name(char token);
    void* get_value(char token);
    void delete_variabel(char token);
};
