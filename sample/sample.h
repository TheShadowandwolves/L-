#include <string>
#include <list>
using namespace std;

class Var{
  public:
    string name;
    string value;
    char type;
};

Var search_var(list<Var>, string);