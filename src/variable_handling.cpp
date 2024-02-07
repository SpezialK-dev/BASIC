#include <ctype.h>
#include <iostream>

class variable_handling
{
private:
    //128 Variable names
    //20 char max lenght rest ist discarded
    unsigned char variable_names[128][21]={""};
    void *value_array[128]; 
    unsigned char find_space_in_variable(unsigned char *name);
    unsigned char last_elem = 0; 
public:
    void create_new_variable(unsigned char  name[], unsigned char value[]);
    unsigned char& get_variable_name(unsigned char token);
    void* get_value(unsigned char token);
    void delete_variabel(unsigned char token);

};

//creation of new variable
// does not return anything might return a statuscode in the future as a char.
void variable_handling::create_new_variable(unsigned char  name[], unsigned char value[]){
  std::cout << "space: " <<int(find_space_in_variable(name))<< std::endl;
  //name array stuff:
  // copying name
  unsigned char working_index = find_space_in_variable(name);
  for(int i = 0; i< 19; ++i){
      variable_names[working_index][i] = name[i];
  };
  variable_names[working_index][20] = '\0';
  

  // value stuff : 
  std::cout <<"isDigit: " << isdigit(value[0]) << " valueItself : " << value[0] <<  std::endl;
  // type detection
  // first 2 values are checked in case its a special value like a string or a float
  if(bool(isdigit(value[0])) || bool(isdigit(value[1]))){

    if(value[0] == 14){
	    //floating creation code
    } 
    else{
	      // I have to go to the max input char limit ? Because theoretically it could be so long 
	      int result = 0;
	      for(int i = 0; i< 120; ++i){
	        if(value[i] == '\0' || value[i] == 0){break;}
	        result = result * 10 + (value[i]- '0');
	      }

	      //getting space and putting variable on stack
	      value_array[working_index] = new int(result);
      }
    }else if(value[0] == 15 || isalpha(value[1])){
      //String code
    }
    //increment last used objekt counter by 1
    if(last_elem != 255){
    ++last_elem;
    }
}
// returns pointer to char array of that type,
// token is the token give by the tokenzier, this is needed for things like scrolleback
unsigned char& variable_handling::get_variable_name(unsigned char token){
     return *variable_names[token];
}
 
//should just return the value of the array at the point of the token
void* variable_handling::get_value(unsigned char token){
  return value_array[token];
}
 
// returns nothing 
// cleans up after variable
void variable_handling::delete_variabel(unsigned char token){
    //name array stuff:
    for(int i = 0; i< 19; ++i){
        variable_names[token][i] = 0;
    };

    //todo copy stuff forwards
    while(variable_names[token+1][0] != 0){
        for(int i = 0; i < 19; ++i){
	  variable_names[token][i] = variable_names[token+1][i];
	  }
        ++token;
	
	}
    // value array stuff :


    //decrementing bc. we reduced size by 1
    if(last_elem !=0){
      --last_elem;
    }
}

//might be replaced in the future so thats why name is in there but for now a slow 
//variant 
unsigned char variable_handling::find_space_in_variable(unsigned char *name){
    return last_elem;
}
