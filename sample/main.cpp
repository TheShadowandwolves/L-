#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include "sample.h"
using namespace std;



void main() {
    list<Var> array;
    Var c, d;
    c.name = "hi";
    c.type = '!';
    c.value = "25";
    d.name = "Bye";
    d.type = '=';
    d.value = "24";
    array.push_back(c);
    array.push_back(d);
    Var found = search_var(array, "c");
    cout << found.name << " " << found.type << " " << found.value;
    
}