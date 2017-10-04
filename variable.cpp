#include "variable.h"
#include "number.h"
#include "atom.h"

bool Variable::match(Variable &a, Atom &b){
  bool isMatch = true;
  if(a.value().length()==0 ){
    a._value = b.value();
  }
  if( a.value() != b.value() ){
    isMatch = false;
  }
  return isMatch;
}

bool Variable::match(Variable &a, Number &b){
  bool isMatch = true;
  if(a.value().length()==0 ){
    a._value = b.symbol();
  }
  if( a.value() != b.symbol() ){
    isMatch = false;
  }
  return isMatch;
}

bool Variable::match(Variable &a, Variable &b){
  bool isMatch = true;
  if(a.value().length()==0  ){
    a._value = b.value();
  }
  if(b.value().length()==0 ){
    b._value = a.value();
  }
  if( a.value() != b.value()){
    isMatch = false;
  }
  if(a.value().length()==0 && b.value().length()==0){
    isMatch = false;
  }
  return isMatch;
}
