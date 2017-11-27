#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <sstream>
#include "variable.h"
#include <typeinfo>

using std::string;
class Number : public Term
{
public:
  Number(double db) : Term(db) {
    isNumber = true;
  }
  bool match(Term &a)
  {
    if (a.isList){
      return false;
     }else if (typeid(a) ==  typeid(Variable)){
       return a.match(*this);
    }else{
      return _symbol == a.symbol();
    }
  }
};

#endif
