#include "atom.h"

bool Atom::match(Atom &b){
  bool isMatch = true;

  if( this->symbol() != b.symbol() ){
    isMatch = false;
  }else{
    this->_value = b.value();
  }
  return isMatch;
}

bool Atom::match( Number &b){
  bool isMatch = true;

  if( this->_symbol() != b.symbol() ){
    isMatch = false;
  }
  return isMatch;
}
bool Atom::match(Variable &a){
  bool isMatch = true;
  if(a.value().empty() ){
      a._value = this->value();
  }
  if( a.value() != this->value() ){
    isMatch = false;
  }
  return isMatch;
}
