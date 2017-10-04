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
    _value = i;
    _symbol = std::to_string(i);
  }

  string symbol(){
    return _symbol;
  }
  int value(){
    return _value;
  }
  bool match( Atom &b);
  bool match(Number &b);
  bool match(Variable &a);
private:
   string _symbol;
   int  _value;
};

#endif
