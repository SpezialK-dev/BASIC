#include <iostream>
#include "../include/editing_window.h"
#include "../include/funktionstable.h"
#include "../include/variable_handling.h"

//can get a max of 255 bytes of input so 255 char array?
//for now I will use this since, this is the amount of Chars that where possible in atari basic

// all the constants of the program
//static const int MaxLineNumb = 32767;

int main(){
  variable_handling *variables = new variable_handling{};
  funktionstable *funktions = new funktionstable{};
  editing_window e{};
  std::cout << "BASIC INTERPRETER 0.1.0\n"<< std::endl;
  e.open_editor(funktions, variables);
  delete variables;
  delete funktions;
  }

