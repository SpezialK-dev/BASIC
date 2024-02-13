#include "ctype.h"
#include "variable_handling.h"

long unsigned int pow_10(int exponent){
    long unsigned int x = 1;
    for(int i = 0; i < exponent; ++i){
      x = x * 10;
    }
    return x;
}


//creation of new variable
// does not return anything might return a statuscode in the future as a char.
void variable_handling::create_new_variable(unsigned char  name[], unsigned char value[]){
    unsigned char working_index = find_space_in_variable(name); 
  // value stuff : 
  // type detection
  // first 2 values are checked in case its a special value like a string or a float
  if(bool(isdigit(value[0])) || bool(isdigit(value[1]))){

    if(value[0] == 14){
	    //floating creation code
	    //floating creation code
      int first_float_part = 0 ;
      int last_float_part = 0;
      int point_in_float = 0;
      int counter_after_point_f = 0;//would like to solve this in another way but I have no clue
      //copying everything before , or . 
      for(int i = 1; i< 120 ; i++){
          if(value[i] == '\0' || value[i] == 0){break;}
          if(value[i] == '.' || value[i] == ','){
            point_in_float = ++i;
            break;
          }
	        first_float_part = first_float_part * 10 + (value[i]-'0');
      }
      //copying part behind the . or , to a new int
      for(point_in_float; point_in_float< 120; ++point_in_float){
	      if(value[point_in_float] == '\0' || value[point_in_float] == 0){break;}
	      last_float_part = last_float_part * 10 + (value[point_in_float]-'0');
        //counter to see how many numbers we have after the . 
        ++counter_after_point_f;
	    }

      float result = float(first_float_part) +(float(last_float_part)/float(pow_10(counter_after_point_f)));
      variables[working_index] = new b_var(name, new unsigned char(1), new float{result});

    } 
    else{
	      // I have to go to the max input char limit ? Because theoretically it could be so long 
	      int result = 0;
	      for(int i = 0; i< 120; ++i){
	        if(value[i] == '\0' || value[i] == 0){break;}
	        result = result * 10 + (value[i]- '0');
	      }


	      //getting space and putting variable on stack
        
	      variables[working_index] = new b_var(name, new unsigned char(1), new int(result));
      }
    }else if(value[0] == 15 || isalpha(value[1])){
      //String code
      //still does not save string contents
      //following problems might have problems getting freed after pointer deletion?
      char* char_pointer = new char[20];
      for(int i = 0; i < 120; ++i){
        //safty net if string terminates before lenght
        if(value[i] == '\0'){
          *(char_pointer+i) = '\0'; 
          break;
        }
        *(char_pointer+i) = value[i];
      }
      // if string terminates after that. this SHOULD be in range and stop things from ending badly
      *(char_pointer+120) = '\0';  
      
      variables[working_index] = new b_var(name, new unsigned char(3), char_pointer);
    }
    //increment last used objekt counter by 1
    if(last_elem != 255){
    ++last_elem;
    }
}
// returns pointer to char array of that type,
// token is the token give by the tokenzier, this is needed for things like scrolleback
unsigned char* variable_handling::get_variable_name(unsigned char token){
     return variables[token]->get_name();
}
 
//should just return the value of the array at the point of the token
void* variable_handling::get_value(unsigned char token){
  return variables[token]->get_pointer();
}
 
// returns nothing 
// cleans up after variable
void variable_handling::delete_variabel(unsigned char token){
    delete variables[token];
    //todo copy stuff forwards
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
