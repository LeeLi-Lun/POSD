#ifndef ATOM_H
#define ATOM_H

#include <string>

#include "number.h"
#include "variable.h"

using std::string;

//class Number;
//class Variable;

class Atom {
public:

  Atom (string s):_symbol(s),_value(s){};

  string symbol(){
    return _symbol;
  }
  string value(){
    return _value;
  }
  bool match( Atom &b);
  bool match( Number &b);
  bool match( Variable &a);
private:
  string  _symbol;
  string  _value;
};


#endif
