#include <iostream>
#include "editor/editing_window.h"
#include "funktions/funktionstable.h"
#include "variables/variable_handling.h"

//can get a max of 255 bytes of input so 255 char array?
//for now I will use this since, this is the amount of Chars that where possible in atari basic

int main(){
  variable_handling *variables = new variable_handling{};
  funktionstable *funktions = new funktionstable{};
  editing_window e{};
  std::cout << "BASIC INTERPRETER 0.1.0\n"<< std::endl;
  e.open_editor(funktions, variables);
}

