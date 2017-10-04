#include "number.h"
#include "atom.h"
//#include "variable.h"

bool Number::match(Number &a, Atom &b){
  bool isMatch = true;

  if( a.symbol()!= b.value() ){
    isMatch = false;
  }
  return isMatch;
}

bool Number::match(Number &a, Number &b){
  bool isMatch = true;

  if( a.value() != b.value() ){
    isMatch = false;
  }else{
      a._value = b.value();
  }
  return isMatch;
}

bool Number::match(Number &b, Variable &a){
  bool isMatch = true;
  if(a.value().length()==0 ){
    a._value = b.symbol();;
  }
  if(a.value() != b.symbol() ){
    isMatch = false;
  }
  return isMatch;
}
