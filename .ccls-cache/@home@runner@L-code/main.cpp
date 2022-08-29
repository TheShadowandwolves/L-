#include <iostream>
#include <string>
#include "Compiler.h"
using namespace std;



int main() {
  string user_input, user_start;
  int eximanation = 1;
  user_start = Write();
  if (user_start == "start"){
      do {
       eximanation = cases();
      }
      while (eximanation != 0);
  }
  else{
     cout << "ERROR: Wrong Input! - Exiting program with -1";
    }
  
}