#include "variable.h"
#include "number.h"
#include "atom.h"

bool Variable::match( Atom &b){
  bool isMatch = true;
  if(this.value().length()==0 ){
    this->_value = b.value();
  }
  if( this.value() != b.value() ){
    isMatch = false;
  }
  return isMatch;
}

bool Variable::match( Number &b){
  bool isMatch = true;
  if(this->value().length()==0 ){
    this->_value = b.symbol();
  }
  if( this->value() != b.symbol() ){
    isMatch = false;
  }
  return isMatch;
}

bool Variable::match( Variable &b){
  bool isMatch = true;
  if(this->value().length()==0  ){
    this->_value = b.value();
  }
  if(b.value().length()==0 ){
    b._value = this->value();
  }
  if( this->value() != b.value()){
    isMatch = false;
  }
  if(this->value().length()==0 && b.value().length()==0){
    isMatch = false;
  }
  return isMatch;
}
