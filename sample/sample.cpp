#include "sample.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

Var search_var(list<Var> array, string gname){
//Create an iterator of std::list
// Make iterate point to begining and incerement it one by one till it reaches the end of list.
//list<Var>::iterator it;
// temp class var contains string name, string value and char type
Var var;


  auto it = std::find_if( std::begin( array ),
                            std::end( array ),
                            [gname]( Var const& v ){ return v.name == gname; } );
        
  if ( array.end() == it )
    {
        std::cout << "item not found" << std::endl;
    }
    else
    {
        const int pos = std::distance( array.begin(), it ) + 1;
        std::cout << "item  found at position " << pos << std::endl;
    }
  var.name = it->name;
  var.value = it->value;
  var.type = it->type;

return var;
}
