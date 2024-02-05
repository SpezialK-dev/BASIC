



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

//variable_handling::variable_handling(/* args */)
//{
//}
//
//variable_handling::~variable_handling()
//{
//}


//creation of new variable
// does not return anything might return a statuscode in the future as a char.
void variable_handling::create_new_variable(char  name[], char value[]){
    
}
// returns pointer to char array of that type,
// token is the token give by the tokenzier, this is needed for things like scrolleback
char& variable_handling::get_variable_name(char token){
     return *variable_names[token];
}

//should just return the value of the array at the point of the token
void* variable_handling::get_value(char token){
    return value_array[token];
}
 
// returns nothing 
// cleans up after variable
void variable_handling::delete_variabel(char token){
    
}