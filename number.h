#ifndef NUMBER_H
#define NUMBER_H

#include "atom.h"

class Number : public Term{
public:
  Number(double value){
    ss << value;
    *_value = ss.str();
  }

  std::string symbol() const {
    return value();
  }
  std::string value() const {
    return *_value;
  }

  std::string getClassName() const {
    return "Number";
  }

  bool match(Term &term){
    bool isMatch = true;

    if(term.getClassName()=="Atom"){
      isMatch = false;
    }else if(term.getClassName()=="Number"){
      Number * ps = dynamic_cast<Number *>(&term);
      if(ps->value() != this->value()){
        isMatch = false;
      }
    }else if(term.getClassName()=="Variable"){
      if(term._value->length()==0){
        *(term._value) = this->value();
      }else{
        isMatch = false;
      }
    }else if(term.getClassName()=="List"){
      isMatch = false;
    }else{//(a.getClassName()=="Struct")

    }
    return isMatch;
  }

  string *_value = new string[1];
private:
  stringstream ss;
};

#endif
