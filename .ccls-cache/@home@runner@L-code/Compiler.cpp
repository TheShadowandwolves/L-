#include "Compiler.h"
#include <iostream>
#include <string>
#include <math.h>
#include <list>
#include <algorithm>
using namespace std;

//class
void Var::print_c(){
      Print(name + " = " + value);
}
// array that stores all variables
list<Var> val_array;

list<Var>::iterator search_val(list<Var>* array, Var var){
//Create an iterator of std::list
std::list<Var>::iterator it;
  list<Var>::iterator is;
// Make iterate point to begining and incerement it one by one till it reaches the end of list.
for (it = array->begin(); it != array->end(); it++)
{
  Print(it->name);
    if(it->name == var.name){
       is = it;
      break;
    }
}
  //Print(is->name);
  return is;
}

bool search_if_val(list<Var>* array, Var var){
//Create an iterator of list
list<Var>::iterator it;

for (it = array->begin(); it != array->end(); it++)
{
  Print(it->name);
    if(it->name == var.name){
      return true;
    }
}
  //Print(is->name);
  return false;
}

void store_val(list<Var>* val_array, Var var)
{
  if (val_array->empty()){
  val_array->push_front(var);
  val_array->begin()->print_c();
    Print("Entering empty");
    }
  else{
    if (!search_if_val(val_array, var)){
      val_array->push_front(var);
      val_array->begin()->print_c();
      Print("Entering not found");
    }
    else{
      Print("Given");
    }
  }
}

//get digits of string and compare if float or int etc.
string erase_var(string var){
  var.erase(0,1);
  return var;
}
 char input_type(string var){
  const char g = var[0];
  //return string
  if ( g == '/'){
    return '/';
  }
    //return int
  else if (g == '$'){
   return '$';
  }
    //return double
  else if (g == '%'){
    return '%';
  }
    //return false
  else{
    return '!';
  }
  
}




//void Print(string txt) { cout << "L-> " << txt << endl; }
template <typename T>  void Print(T num){cout << "L-> " << num << endl; }
//void Print(int num) { cout << "L-> " << num << endl; }
//void Print(double num) { cout << "L-> " << num << endl; }
void Print() { cout << "L-> "; }
string Write() {
  Print();
  string txt;
  cin >> txt;
  return txt;
}

enum Choices {add, sub, div, mul, powr, load, write, print, read, scan, endFile, help};

int enumFind(){
  int ok = 0;
  do{
    ok = 0;
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
    ok =1;
  }
    }
    while(ok == 1);
}

int cases()
  {
    int enumVar = enumFind();
    string val;
    Var var1;
    string num1, num2;
    int res_i;
    double res_d;
    string res_s;
    switch (enumVar)
    {
        case 0:
        {
// needs to implement that previous variables can be taken
          Print("add");
          cin >> val;
          var1.name = val;
          cin >> num1;
          cin >> num2;
          Print(num1);
          if (input_type(num1) == '$' && input_type(num2) == '$'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_i = stoi(num1) + stoi(num2);
            var1.value = to_string(res_i); 
            var1.type = "int";
          }
          else if (input_type(num1) == '%' && input_type(num2) == '%'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_d = stod(num1) + stod(num2);
            var1.value = to_string(res_d); 
            var1.type = "double";
          }
          else if (input_type(num1) == '/' && input_type(num2) == '/'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_s = num1 + num2;
            var1.value = res_s; 
            var1.type = "string";
          }
          else if (input_type(num1) == '$' && input_type(num2) == '%' || input_type(num1) == '%' && input_type(num2) == '$'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_d = stod(num1) + stod(num2) + 0.0;
            var1.value = to_string(res_d); 
            var1.type = "double";
          }
          else {
            Print("Invalid Operation - cannot convert types");
            break;
          }
         
          store_val(&val_array, var1);
          var1.print_c();
  
            // do stuff
            break;
        }
        case 1:
        {
          Print("sub");
          cin >> val;
          var1.name = val;
          cin >> num1;
          cin >> num2;

          if (input_type(num1) == '$' && input_type(num2) == '$'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_i = stoi(num1) - stoi(num2);
            var1.value = to_string(res_i); 
            var1.type = "int";
          }
          else if (input_type(num1) == '%' && input_type(num2) == '%'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_d = stod(num1) - stod(num2);
            var1.value = to_string(res_d); 
            var1.type = "double";
          }
          else if (input_type(num1) == '/' || input_type(num2) == '/'){
            Print("Invalid Operation - cannot sub strings");
            break;
          }
          else if (input_type(num1) == '$' && input_type(num2) == '%' || input_type(num1) == '%' && input_type(num2) == '$'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_d = stod(num1) - stod(num2) + 0.0;
            var1.value = to_string(res_d); 
            var1.type = "double";
          }
          else {
            Print("Invalid Operation - cannot convert types");
            break;
          }
          store_val(&val_array, var1);
          var1.print_c();

            // do stuff
            break;
        }
        case 2:
        {
          Print("div");
          cin >> val;
          var1.name = val;
          cin >> num1;
          cin >> num2;
   if (input_type(num1) == '$' && input_type(num2) == '$'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            if (stoi(num2)){
            res_i = stoi(num1) / stoi(num2);
            var1.value = to_string(res_i); 
            var1.type = "int";
              }
            else{
                Print("Invalid Operation - cannot div by 0");
             }
          }
          else if (input_type(num1) == '%' && input_type(num2) == '%'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            if (stod(num2)){
            res_d = stod(num1) / stod(num2);
            var1.value = to_string(res_d); 
            var1.type = "double";
              }
            else{
                Print("Invalid Operation - cannot div by 0");
             }
          }
          else if (input_type(num1) == '/' || input_type(num2) == '/'){
            Print("Invalid Operation - cannot div strings");
            break;
          }
          else if (input_type(num1) == '$' && input_type(num2) == '%' || input_type(num1) == '%' && input_type(num2) == '$'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            if (stod(num2)){
            res_d = stod(num1) - stod(num2) + 0.0;
            var1.value = to_string(res_d); 
            var1.type = "double";
              }
          }
          else {
            Print("Invalid Operation - cannot convert types");
            break;
          }
            // do stuff
          store_val(&val_array, var1);
          var1.print_c();
            break;
        }
        case 3:
        {
          Print("mul");
          cin >> val;
          var1.name = val;
          cin >> num1;
          cin >> num2;

          if (input_type(num1) == '$' && input_type(num2) == '$'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_i = stoi(num1) * stoi(num2);
            var1.value = to_string(res_i); 
            var1.type = "int";
          }
          else if (input_type(num1) == '%' && input_type(num2) == '%'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_d = stod(num1) * stod(num2);
            var1.value = to_string(res_d); 
            var1.type = "double";
          }
          else if (input_type(num1) == '/' || input_type(num2) == '/'){
            Print("Invalid Operation - cannot mul strings");
            break;
          }
          else if (input_type(num1) == '$' && input_type(num2) == '%' || input_type(num1) == '%' && input_type(num2) == '$'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_d = stod(num1) - stod(num2) + 0.0;
            var1.value = to_string(res_d); 
            var1.type = "double";
          }
          else {
            Print("Invalid Operation - cannot convert types");
            break;
          }
          
          store_val(&val_array, var1);
          var1.print_c();
            // do stuff
            break;
        }
        case 4:
        {
          Print("powr");
          cin >> val;
          var1.name = val;
          cin >> num1;
          cin >> num2;
         // var1.value = to_string(pow(num1, num2)); 
         

          if (input_type(num1) == '$' && input_type(num2) == '$'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_i = pow(stoi(num1) , stoi(num2));
            var1.value = to_string(res_i); 
            var1.type = "int";
          }
          else if (input_type(num1) == '%' && input_type(num2) == '%'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_d = pow(stod(num1) , stod(num2));
            var1.value = to_string(res_d); 
            var1.type = "double";
          }
          else if (input_type(num1) == '/' || input_type(num2) == '/'){
            Print("Invalid Operation - cannot mul strings");
            break;
          }
          else if (input_type(num1) == '$' && input_type(num2) == '%' || input_type(num1) == '%' && input_type(num2) == '$'){
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_d = stod(num1) - stod(num2) + 0.0;
            var1.value = to_string(res_d); 
            var1.type = "double";
          }
          else {
            Print("Invalid Operation - cannot convert types");
            break;
          }
          
          
          store_val(&val_array, var1);
          var1.print_c();
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
            Help();
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

void Help(){
   Print("HELP: \n \n MATH INPUTS: \n \n 'add', 'sub', 'div', 'mul', 'powr'\n Insert two number afterwards with space between\n \nTEXT INPUT: \n \n'write' - writes line of text into file\n 'print' - prints out a certain text \n\n FILE INPUT: \n\n 'open' - opens file \n 'close' - closes file \n 'load' - loads the code inside file \n 'read' - reads text of file ('start', 'end')\n 'scan' - write text to file \n\n PROGRAM INPUTS: \n \n'start' - starts the program \n 'endFile' - exit program\n\n");
}