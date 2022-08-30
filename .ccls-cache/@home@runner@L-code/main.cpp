#include <iostream>
#include <string>
#include "Compiler.h"
using namespace std;

void start(int eximanation){
      do {
       eximanation = cases();
      }
      while (eximanation != 0);
}

int main() {
  string user_input, user_start;
  int eximanation = 1;
  user_start = Write();
  if (user_start == "start"){
    start(eximanation);
  }
  else if(user_start == "help"){
      Help();
      start(eximanation);
    }
  else{
     cout << "ERROR: Wrong Input! - Exiting program with -1";
    }
  
}