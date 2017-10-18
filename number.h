#ifndef NUMBER_H
#define NUMBER_H

#include "term.h"

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

    }else{//(a.getClassName()=="Struct")

    }
    return isMatch;
  }

  string *_value = new string[1];
private:
  stringstream ss;
};

#endif
