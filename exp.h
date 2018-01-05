#ifndef EXP_H
#define EXP_H

#include "atom.h"
#include <string>

class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string getChar() = 0;
  virtual Term * getleft(){};
  virtual Term * getright(){};
  virtual Exp * getleftEXP(){};
  virtual Exp * getrightEXP(){};
  virtual string getMatchEXPString(){};
};


class MatchExp : public Exp {
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right){

  }
  string getChar(){
    return "=";
  }

  bool evaluate(){
    return _left->match(*_right);
  }

  Term * getleft(){
    return _left;
  }

  Term * getright(){
    return _right;
  }

  string getMatchEXPString(){
    string r;

    if(evaluate())
      if(getleft()->symbol() != getright()->symbol())
        r = ( getleft()->symbol() + " = " +  getright()->value() );
      else
        r = "true";
    else
      r = "false";

    return r;
  }

private:
  Term* _left;
  Term* _right;
};

class ConjExp : public Exp {
public:
  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }
  string getChar(){
    return ", ";
  }

  Exp * getleftEXP(){
    return _left;
  }

  Exp * getrightEXP(){
    return _right;
  }

  bool evaluate() {
    return (_left->evaluate() && _right->evaluate());
  }
private:
  Exp * _left;
  Exp * _right;
};

class DisjExp : public Exp {
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  string getChar(){
    return "; ";
  }

  Exp * getleftEXP(){
    return _left;
  }

  Exp * getrightEXP(){
    return _right;
  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }
private:
  Exp * _left;
  Exp * _right;
};
#endif
