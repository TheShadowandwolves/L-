#include <iostream>
#include <string>
#include "Compiler.h"
using namespace std;

void start(int eximanation, list<Var>* val_array){
      do {
       eximanation = cases(val_array);
      }
      while (eximanation != 0);
}

int main() {
  list<Var> val_array;
  string user_input, user_start;
  int eximanation = 1;
  user_start = Write();
  if (user_start == "start"){
    start(eximanation, &val_array);
  }
  else if(user_start == "help"){
      Help();
      start(eximanation, &val_array);
    }
  else{
     cout << "ERROR: Wrong Input! - Exiting program with -1";
    }
  
}