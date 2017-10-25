#ifndef LIST_H
#define LIST_H

#include "variable.h"
#include <stdexcept>
#include <vector>

using std::vector;
using std::out_of_range;

class List : public Term {
public:

  string getClassName() const {
     return "List";
   }

  string symbol() const{
    string ret = "[";

    if(_elements.empty()){
      ret += "]";
    }else{
      for(int i = 0; i < _elements.size() - 1 ; i++){
        ret += _elements[i]-> symbol() + ", ";
      }
      ret += _elements[_elements.size()-1]-> symbol() +"]";
    }
    *_symbol = ret;
    return  *_symbol;
  };

  string value() const{
    string ret = "[";

    if(_elements.empty()){
      ret += "]";
    }else{
      for(int i = 0; i < _elements.size() - 1 ; i++){
        if(_elements[i]-> value().length()==0){
          ret += _elements[i]-> symbol() + ", ";
        }else{
          ret += _elements[i]-> value() + ", ";
        }
      }
      ret += _elements[_elements.size()-1]-> value() +"]";
    }
    *_value = ret;
    return  *_value;
  }

  bool match(Term & term){
    bool isMatch = true;

    if(term.getClassName()=="Atom"){
      isMatch = false;
    }

    if(term.getClassName()=="Number"){
      isMatch = false;
    }

    if(term.getClassName()=="Struct"){
      isMatch = false;
    }

    if(term.getClassName()=="List"){
      List * ps = dynamic_cast<List *>(&term);
      if(ps->_elements.size()!=_elements.size())
        return false;
      if(ps->symbol()!=symbol()){
        for(int i = 0; i < _elements.size() - 1 ; i++){
          if(ps->_elements[i]->value() != _elements[i]->value()){
            if (_elements[i]->getClassName()=="Variable"){
              isMatch =_elements[i]->match(*ps->_elements[i]);
            }else{  isMatch =  false;}
          }
        }
      }else{}

    }
    return isMatch;
  }

  string *_value = new string[1];
  string *_symbol = new string[1];

public:
  List (): _elements() {}
  List (vector<Term *> const & elements):_elements(elements){}
  Term * head() const{

    if(_elements.size()==0){
      throw string("Accessing head in an empty list") ;
    }else{
      return _elements[0];
    }
  }

  List * tail() const{
    if(_elements.size()==0){
      throw string("Accessing head in an empty list");
    }else{
      vector<Term *> v;
      for(int i = 1; i < _elements.size() ; i++){
        v.push_back(_elements[i]);
      }
      List *l = new List(v);

      return l;
    }
  }


private:
  vector<Term *> _elements;

};

#endif
