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
  bool match(Number &a, Atom &b);
  bool match(Number &a, Number &b);
  bool match(Number &b, Variable &a);
private:
   string _symbol;
   int  _value;
};

#endif
