#include <iostream>
#include "editor/editing_window.h"
#include "funktions/funktionstable.h"
#include "variables/variable_handling.h"

//can get a max of 255 bytes of input so 255 char array?
//for now I will use this since, this is the amount of Chars that where possible in atari basic

int main(){
    
  //std::cout << "hello World" << std::endl;
    
  // variable Handling test code
  //variable_handling v;
  //unsigned char test[20]{"Hello World"};
  //unsigned char test2[20]{"Goodbye World"};
  //char test2_sig[20]{"Goodbe Wyorld"};
  //char test_sig[10]{"12344"};
  //unsigned char test_v[10]{"123"};
  //unsigned char test_f[15]{14, '2' ,'4','1','3','.','1','2','5','4','9','\0'};
  //v.create_new_variable(test,test_v);
  //v.create_new_variable(test2,test);
  //v.create_new_variable(test,test_f);
  ////testing return values
  //unsigned char* return_test;
  //unsigned char* return_test2;
  //int* return_var_test;
  //char* return_var_test2;
  //float* return_var_test3;
  //return_test =  v.get_variable_name(0);
  //return_test2 =v.get_variable_name(1);
  //return_var_test3 = static_cast<float*>(v.get_value(2));
  //return_var_test = static_cast<int*>(v.get_value(0));
  //return_var_test2 = static_cast<char*>(v.get_value(1));
  //std::cout << return_test << " :: "<< *return_var_test <<" | " << return_test2 <<  " :: "<< *(return_var_test2) << "\n Just Float Value: "
  //<< *(return_var_test3)  << std::endl;
  
  // testing delete Statment
  //v.delete_variabel(0); 
  //return_test = v.get_variable_name(0);
  //std::cout << return_test << std::endl;
  // testing funk var
  //funk_var testFunk{'x' ,test_sig, test2_sig};
  variable_handling variables{};
  funktionstable funktions{};
  editing_window e{};
  std::cout << "BASIC INTERPRETER 0.1.0\n"<< std::endl;
  e.open_editor(&funktions, &variables);
}

