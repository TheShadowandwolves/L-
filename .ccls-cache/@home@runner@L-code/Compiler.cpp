#include "Compiler.h"
#include <iostream>
#include <string>
#include <math.h>>
using namespace std;

void Print(string txt) { cout << "L-> " << txt << endl; }
void Print(int num) { cout << "L-> " << num << endl; }
void Print(double num) { cout << "L-> " << num << endl; }
void Print() { cout << "L-> "; }
string Write() {
  Print();
  string txt;
  cin >> txt;
  return txt;
}

enum Choices {add, sub, div, mul, powr, load, write, print, read, scan, endFile, help};

int enumFind(){
  string txt = Write();
  if (txt== "add"){
    return 0;
  }
  else if (txt == "sub"){
    return 1;
  }
  else if (txt == "div"){
    return 2;
  }
  else if (txt == "mul"){
    return 3;
  }
  else if (txt == "powr"){
    return 4;
  }
  else if (txt== "load"){
    return 5;
  }
  else if (txt== "write"){
    return 6;
  }
  else if (txt == "print"){
    return 7;
  }
    else if (txt == "read"){
    return 8;
  }
    else if (txt == "scan"){
    return 9;
  }
  else if (txt == "endFile"){
    return 10;
  }
  else if (txt == "help"){
    return 11;
  }
  else {
    cout << "Wrong input code - cannot understand " << txt << endl;
    Print("Try to input help for all codes available");
    return -1;
  }
}

int cases()
  {
    int enumVar = enumFind();
    double num1, num2;
    switch (enumVar)
    {
        case 0:
        {
          Print("add");
          cin >> num1;
          cin >> num2;
          Print(num1 + num2);
            // do stuff
            break;
        }
        case 1:
        {
          Print("sub");
          cin >> num1;
          cin >> num2;
          Print(num1 - num2);
            // do stuff
            break;
        }
        case 2:
        {
          Print("div");
          cin >> num1;
          cin >> num2;
          if (num2 == 0){
            Print("ERROR Invalid Math operation");
          }
          else{
            Print(num1 / num2);
          }
          
            // do stuff
            break;
        }
        case 3:
        {
          Print("mul");
          cin >> num1;
          cin >> num2;
          Print(num1 * num2);
            // do stuff
            break;
        }
        case 4:
        {
          Print("powr");
          cin >> num1;
          cin >> num2;
          Print(pow(num1, num2));
            // do stuff
            break;
        }
        case 5:
        {
            // do stuff
            break;
        }
        case 6:
        {
            // do stuff
            break;
        }
        case 7:
        {
            // do stuff
            break;
        }
        case 8:
        {
        
            // do stuff
            break;
        }
        case 9:
        {
         
            // do stuff
            break;
        }
        case 10:
        {
          return 0;
            // do stuff
            break;
        }
        case 11:
        {
          Print("HELP: \n \n MATH INPUTS: \n \n 'add', 'sub', 'div', 'mul', 'powr'\n Insert two number afterwards with space between\n \nTEXT INPUT: \n \n'write' - writes line of text into file\n 'print' - prints out a certain text \n\n FILE INPUT: \n\n 'open' - opens file \n 'close' - closes file \n 'load' - loads the code inside file \n 'read' - reads text of file ('start', 'end')\n 'scan' - write text to file \n\n PROGRAM INPUTS: \n \n'start' - starts the program \n 'endFile' - exit program\n\n");
            // do stuff
            break;
        }
        default:
        {
            return 0;
            // is likely to be an error
        }
    }
  return 1;
}
