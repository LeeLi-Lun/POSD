#ifndef TERM_H
#define TERM_H

#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::stringstream;
using std::vector;

class Term{

public:

  virtual string symbol() const {
    return value();
  }

  virtual string value() const = 0;

  virtual string getClassName() const {
    return "Term";
  }
  virtual bool match(Term & term) {
    return symbol() == term.symbol();
  }

  string *_symbol;
  string *_value;
};

class Atom : public Term{
public:
  Atom (string s){
      *_symbol = s;
  }

  string symbol() const{
    return *_symbol;
  }
  string value() const{
    return symbol();
  }

 string getClassName() const {
    return "Atom";
  }

  bool match(Term &term){
    bool isMatch = true;

    if(term.getClassName()=="Atom"){
      Atom * ps = dynamic_cast<Atom *>(&term);
      if(ps->symbol() != this->symbol()){
        isMatch = false;
      }
    }else if(term.getClassName()=="Number"){
      isMatch = false;
    }else if(term.getClassName()=="Variable"){

      if(term._value->length()==0){
        *(term._value) = this->symbol();
      }else{
        isMatch = false;
      }

    }else if(term.getClassName()=="List"){
      isMatch = false;
    }else{//(a.getClassName()=="Struct")

    }
    return isMatch;
  }

  string *_symbol = new string[1];
};

#endif
