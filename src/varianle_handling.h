
class variable_handling
{
private:
    //128 Variable names
    //20 char max lenght rest ist discarded
    char variable_names[128][20]={""};
    void* value_array[128];
public:
    //variable_handling(/* args */);
    //~variable_handling();
    void create_new_variable(char  name[], char value[]);
    char& get_variable_name(char token);
    void* get_value(char token);
    void delete_variabel(char token);
};