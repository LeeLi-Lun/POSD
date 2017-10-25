#ifndef VARIABLE_H
#define VARIABLE_H

#include "number.h"

class Variable : public Term{
public:
  
public:
  Variable(string s):Term(s){
    *_inst = "0";
  }
  string value() const {
    if (_inst)
      return _inst->value();
    else
      return Term::value();
  }
  bool match( Term & term ){
    if (this == &term)
      return true;
    if(!_inst){
      _inst = &term ;
      return true;
    }
    return _inst->match(term);
  }
private:
  Term * _inst;
  
/*
  Variable(string s):_symbol(s),temp(0){}

  string symbol() const {
    return _symbol;
  }

  string value() const {
    return *_value;
  }
*/
  string getClassName() const {
     return "Variable";
   }
/*
   bool match(Term &term){
     bool isMatch = true;
     if(term.getClassName()=="Atom"){
       Atom * ps = dynamic_cast<Atom *>(&term);
       if(this->_value->length()==0){
         *_value = ps->symbol();
          ps->_symbol = this->_value;
     }
       if( *_value != term.symbol() ){
         isMatch = false;
       }
     }
     if(term.getClassName()=="Number"){
       Number * ps = dynamic_cast<Number *>(&term);
       if(this->_value->length()==0 ){
         temp = &term;
         _value = temp->_value;
       }
       if( this->value() != term.value() ){
         isMatch = false;
       }
     }

     if(term.getClassName()=="Variable"){
       Variable * ps = dynamic_cast<Variable *>(&term);
       if(this->_value->length()==0 && ps->_value->length()!=0){
         this->_value = ps->_value;
       }
       if(ps->_value->length()==0 && this->_value->length()!=0){
         ps->_value = this->_value;
       }
       if( this->value() != ps->value()){
         isMatch = false;
       }else//(this->value().length()==0 && ps->value().length()==0)
       {
         ps->_value = this->_value ;
       }
     }
     if(term.getClassName()=="Struct"){
       if(this->_value->length()==0){
         *_value = term.value();
       }else{
         isMatch = false;
       }
     }
     if(term.getClassName()=="List"){
       if( this->_value->length()==0){
         *_value = term.value();
       }else{
         isMatch = false;
       }
     }

     return isMatch;
   }
*/

private:
  string *_value = new string[1];
  string _symbol;
};

#endif
