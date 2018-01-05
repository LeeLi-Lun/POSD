#ifndef SHELL_H
#define SHELL_H

#include "scanner.h"
#include "parser.h"
#include "exp.h"
#include <vector>

class Shell{
public:
  Shell(Parser p): _p(p){
    _p.getExpressionTree()->evaluate();
  }
  string getResults(){
    string _reslut;
    string _temp;
    root = _p.getExpressionTree();
    for(temp = root; temp->getChar()!= "=";temp = temp->getrightEXP()){
        _reslut += ( temp->getleftEXP()->getMatchEXPString());
        _reslut += temp->getChar();
        string_it ++ ;
    }
    if( temp->getMatchEXPString() != "true"){
      _reslut += ( temp->getMatchEXPString());
      _reslut += ".";
    }
    if(temp->getMatchEXPString() == "true"){
      _reslut.erase(_reslut.begin()+(string_it*6));
      _reslut.replace(_reslut.begin()+(string_it*6),_reslut.begin()+(string_it*6)+1,".");
    }

    return _reslut;
  }

  string getResult(){
    string _reslut;
    string _temp;

    root = _p.getExpressionTree();

    if (root->getChar()==";"){
      return getResults();
    }
    for(temp = root; temp->getChar()!= "=";temp = temp->getleftEXP()){
          _exptemp.push(temp);

    }
    _temp = temp->getMatchEXPString();
    _reslut += _temp;
    if(temp->getMatchEXPString()=="true" && (!_exptemp.empty())){
      _reslut = "";
    }
    while(!_exptemp.empty()){
      temp = _exptemp.top();
      if (temp->getrightEXP()->getMatchEXPString() == "false"){
            _reslut = "false";
      }else if( _reslut=="" && temp->getrightEXP()->getMatchEXPString() == "true"){
          _reslut = "true";
      }else if(temp->getrightEXP()->getMatchEXPString() == "true"){

      }else if(_reslut==""){
          _reslut += ( temp->getrightEXP()->getMatchEXPString());
      }else if(_temp == temp->getrightEXP()->getMatchEXPString()){

      }else{
          _reslut += temp->getChar();
          _reslut += ( temp->getrightEXP()->getMatchEXPString());
          _temp = temp->getrightEXP()->getMatchEXPString();
      }
      _exptemp.pop();
    }
    _reslut += ".";

    // if( temp->getChar()!= "="){
    //   _reslut += temp->getMatchEXPString()+ ".";
    // }
    // else{
    //   _reslut += temp->getMatchEXPString() + ".";
    //   if(temp->getMatchEXPString() == "false")
    //     _reslut = "false.";
    // }
    return _reslut;
  }

private:
  Parser _p;
  int string_it =0;
  Exp* root;
  Exp* temp;
  stack<Exp*> _exptemp;
};
#endif
