#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "variable.h"

using std::string;

class Atom;
//class Variable;

class Number{
public:
  Number(int i){
    _value = std::to_string( i);
    _symbol = std::to_string(i);
  }

  string symbol(){
    return _symbol;
  }
  string value(){
    return _value;
  }
  bool match( Atom &b);
  bool match(Number &b);
  bool match(Variable &a);
private:
   string _symbol;
   string  _value;
};

#endif
