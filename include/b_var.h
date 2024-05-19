#ifndef b_var_h
#define b_var_h

class b_var
{
public:
  enum Types{end,undefined, integer,floating_p,string,exit,anytype,};//should be used to replace the int values for types
  //constructor
  //used to create an anonymus pointer
  b_var(void* in_pointer);
  inline b_var(unsigned char in_name[],Types  in_type, void* in_pointer );
    inline b_var();

    b_var(const b_var&);

  // DESTRUCTOR
  ~b_var();
  //GET METHODES
  void* get_pointer()const;
    Types get_type()const;
    unsigned char* get_name();

private:
  Types type;
  //unsigned char* type;
    void* pointer; 
    unsigned char name[20]{""};

};

//constructor
b_var::b_var(unsigned char in_name[], Types in_type, void* in_pointer ) : type{in_type} , pointer{in_pointer} 
{
    for(int i = 0; i< 19; ++i){
      name[i] = in_name[i];
    };
    name[19] = '\0';
    
    // 0 = undefined // VOID 
    // 1 = int
    // 2 = Float
    // 3 = String
    // 4 = Exit Type 
    // for intype
    
}
b_var::b_var(){
  type = undefined;
    unsigned char no_name[20]{"NOTDEFINED"};
    for(int i = 0; i< 19; ++i){
      name[i] = no_name[i];
    };
    name[19] = '\0';
}

#endif /* b_var_h */
