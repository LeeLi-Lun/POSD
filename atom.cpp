#include "include/atom.h"

bool Atom::match(Atom &a, Atom &b){
  bool isMatch = true;

  if( a.symbol() != b.symbol() ){
    isMatch = false;
  }else{
    a._value = b.value();
  }
  return isMatch;
}

bool Atom::match(Atom &a, Number &b){
  bool isMatch = true;

  if( a.symbol() != b.symbol() ){
    isMatch = false;
  }
  return isMatch;
}
bool Atom::match(Atom &b , Variable &a){
  bool isMatch = true;
  if(a.value().empty() ){
      a._value = b.value();
  }
  if( a.value() != b.value() ){
    isMatch = false;
  }
  return isMatch;
}
