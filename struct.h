#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"

class Struct : public Term{
public:
  Struct(Atom const & name, std::vector<Term *> args):_name(name),_args(args){}

  Term * args(int index) {
    return _args[index];
  }

  string getClassName() const {
    return "Struct";
  }

  Atom const & name() {
    return _name;
  }

  string symbol() const{
    string ret =_name.symbol() + "(";
    for(int i = 0; i < _args.size() - 1 ; i++){
      ret += _args[i]-> symbol() + ", ";
    }
      ret += _args[_args.size()-1]-> symbol() + ")";
    return  ret;
  }

  string value() const{
    *_value =_name.symbol() + "(";
    for(int i = 0; i < _args.size() - 1 ; i++){
      if(_args[i]->value().empty()){
        *_value += _args[i]-> symbol() + ", ";
      }else{
        *_value += _args[i]-> value() + ", ";
      }
    }
    if(_args[_args.size()-1]->value().empty()){
        *_value += _args[_args.size()-1]-> symbol() + ")";
    }else{
          *_value += _args[_args.size()-1]-> value() + ")";
    }
    return  *_value;
  }

  bool match(Term &term){
    bool isMatch = true;
    if(term.getClassName()=="Atom"){
    }

    if(term.getClassName()=="Number"){
    }

    if(term.getClassName()=="Variable"){
    }

    if(term.getClassName()=="List"){
      isMatch = false;
    }

    if(term.getClassName()=="Struct"){
      Struct * ps = dynamic_cast<Struct *>(&term);
      if (ps){
        if (!_name.match(ps->_name))
          return false;
        if(_args.size()!= ps->_args.size())
          return false;
        for(int i=0;i<_args.size();i++){
          if(_args[i]->symbol() != ps->_args[i]->symbol())
              return false;
        }
        return true;
      }
      return false;
    }
  }

  string *_value = new string[1];
private:
  Atom _name;
  std::vector<Term *> _args;

};

#endif
