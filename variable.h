#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

using std::string;

class Number;
class Atom;

class Variable{

public:

  Variable(string s):_symbol(s){}

  string symbol(){
    return _symbol;
  }
  string value(){
    return _value;
  }
  bool match( Atom &b);
  bool match(Number &b);
  bool match( Variable &b);

  string _value ;
private:
  string  _symbol;
};

#endif
