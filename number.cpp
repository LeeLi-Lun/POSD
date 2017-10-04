#include "number.h"
#include "atom.h"
//#include "variable.h"

bool Number::match( Atom &b){
  bool isMatch = true;

  if( this->value() != b.symbol() ){
    isMatch = false;
  }
  return isMatch;
}

bool Number::match( Number &b){
  bool isMatch = true;

  if( this->value() != b.value() ){
    isMatch = false;
  }else{
      this->_value = b.value();
  }
  return isMatch;
}

bool Number::match(Variable &a){
  bool isMatch = true;
  if(a.value().length()==0 ){
    a._value = this->value();
  }
  if(a.value() != this->value() ){
    isMatch = false;
  }
  return isMatch;
}
