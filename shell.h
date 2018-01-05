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

  string getResult(){
    string _reslut;
    string _temp;
    root = _p.getExpressionTree();
    for(temp = root; temp->getChar()!= "=";temp = temp->getleftEXP()){
          _exptemp.push(temp);
          // if (temp->getChar()==",")
    }
    _temp = temp->getMatchEXPString();
    _reslut += _temp;
    if(temp->getMatchEXPString()=="true" && (!_exptemp.empty())){
      _reslut = "";
    }
    // if (temp->getChar()==","){
    //   isCon = 1;
    // }
    while(!_exptemp.empty()){
      temp = _exptemp.top();
      if (temp->getChar()==";"){
        isDisCon = 1;
      }
      if (temp->getrightEXP()->getMatchEXPString() == "false"){
          if(!isDisCon)
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
  int isCon = 0;
  int isDisCon = 0;
  Exp* root;
  Exp* temp;
  stack<Exp*> _exptemp;
};
#endif
