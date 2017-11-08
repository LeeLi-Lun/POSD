#ifndef LIST_H
#define LIST_H

#include "atom.h"

#include <vector>
#include <list>
#include <string>
#include <stdexcept>
using namespace std;

class List : public Term {
public:
  string symbol() const {

    string ret = "[";
    if(_elements.empty()){
        ret += "]";
    }else {
        for (int i = 0; i < _elements.size() -1; i++){
            ret += _elements[i]->symbol()+", ";
        }
        ret += _elements[_elements.size()-1]->symbol()+"]";
    }
    return ret;
  }

  string value() const {

    string ret = "[";
    if(_elements.empty()){
        ret += "]";
    }else{
        for (int i = 0; i < _elements.size() -1; i++){
            ret += _elements[i]->symbol()+", ";
        }
        ret += _elements[_elements.size()-1]->symbol()+"]";
    }

    if(ret == "[error]"){
        ret = "Accessing head in an empty list";
    }
    return ret;
  }

  string getClassName() const {return "List";}

  bool match(Term & term) {
    if(term.getClassName() == "List"){
        List * ps = dynamic_cast<List *>(&term);
        if (ps){
          if(_elements.size()!= ps->_elements.size())
            return false;
          for(int i=0;i<_elements.size();i++){
            if(_elements[i]->value() != ps->_elements[i]->value()){
                if(_elements[i]->getClassName() == "Variable" ||
                    ps->_elements[i]->getClassName() == "Variable"){
                    _elements[i]->match(*ps->_elements[i]);
                    continue;
                }else {
                    return false;
                }
            }
          }
          return true;
        }
        return false;
    }else if(term.getClassName() == "Variable"){
        return term.match(*this);
    }else{
        return true;
    }
  }

public:
  List (): _elements() {};
  List (vector<Term *> elements):_elements(elements){};
  Term * elements(int index) {
    return _elements[index];
  }

  Term * head() const {
    if(_elements.size()!=0) return _elements[0];
    else {
        Atom *errStr = new Atom("Accessing head in an empty list");
        return errStr;
    }
    return 0;
  }

  List * tail() const {
      List *l;
      vector <Term *> tailList;
      if(_elements.size()!=0) {
        for(int i=1;i<_elements.size();i++){

             tailList.push_back(_elements[i]);
        }
        l=new List(tailList);
        return l;
      }else {
        Atom *errStr = new Atom("error");
        tailList.push_back(errStr);
        l=new List(tailList);
        return l;
      }

      return 0;
  }

private:
  vector<Term *> _elements;

};

#endif
