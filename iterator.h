#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include "struct.h"
#include "list.h"
#include <queue>
#include <stack>
#include <vector>
// #include <algorithm>
template <class T>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual T currentItem() const = 0;
  virtual bool isDone() const = 0;
};

class BFSIterator :public Iterator<Term*>{
public:
  BFSIterator(Term *n):_n(n){}

  void first(){
    Iterator<Term*> *it = _n->createIterator();
    for(it->first();!(it->isDone()); it->next()){
      Tempqueue.push(it->currentItem());
      BFSqueue.push(it->currentItem());
    }
    while(Tempqueue.size()!=0){
      Iterator<Term*> *it2 =  Tempqueue.front()->createIterator();
      Tempqueue.pop();
      if(!(it2->isDone())){
        for(it2->first();!(it2->isDone()); it2->next()){
          Tempqueue.push(it2->currentItem());
          BFSqueue.push(it2->currentItem());
        }
      }else{
        // BFSqueue.push(it2->currentItem());
      }
    }
  }

  void next(){
    BFSqueue.pop();
  }

  Term * currentItem() const{
    return BFSqueue.front();
  }

  bool isDone() const{
    return BFSqueue.empty();
  }

  private:
  std::queue<Term *> BFSqueue;
  std::queue<Term *> Tempqueue;
  int _index;
  Term* _n;
};

class DFSIterator :public Iterator<Term*>{
public:
  DFSIterator(Term *n):_n(n){}

  void first(){
    Iterator<Term*> *it = _n->createIterator();
    for(it->first();!(it->isDone()); it->next()){
      Tempvector.push_back(it->currentItem());
    }
    while(Tempvector.size()!=0){
      // DFSstack.push(Tempvector.back());
      Tempstack.push(Tempvector.back());
      Tempvector.pop_back();
    }
    while(Tempstack.size()!=0){
      Iterator<Term*> *it2 = Tempstack.top()->createIterator();
      Term* _term = Tempstack.top();
        if(!(it2->isDone())){
          Tempstack.pop();
          for(it2->first();!(it2->isDone()); it2->next()){
            Tempvector.push_back(it2->currentItem());
          }
          while(Tempvector.size()!=0){
            Tempstack.push(Tempvector.back());
            Tempvector.pop_back();
          }
          DFSqueue.push(_term);
        }else{
          Tempstack.pop();
          DFSqueue.push(_term);
        }
    }
  }

  void next(){
    DFSqueue.pop();
  }

  Term * currentItem() const{
    return DFSqueue.front();
  }

  bool isDone() const{
    return DFSqueue.empty();
  }

private:
  std::queue<Term *> DFSqueue;
  std::stack<Term *> Tempstack;
  std::vector<Term *> Tempvector;
  Term* _n;
};


class NullIterator :public Iterator<Term*>{
public:
  NullIterator(Term *n){}
  void first(){}
  void next(){}
  Term * currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  }

};

class StructIterator :public Iterator<Term*> {
public:
  StructIterator(Struct *s): _index(0), _s(s) {}

  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _s->args(_index);
  }

  bool isDone() const {
    return _index >= _s->arity();
  }

  void next() {
    _index++;
  }
private:
  int _index;
  Struct* _s;
};

class ListIterator :public Iterator<Term*> {
public:
  ListIterator(List *list): _index(0), _list(list) {}

  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _list->args(_index);
  }

  bool isDone() const {
    return _index >= _list->arity();
  }

  void next() {
    _index++;
  }
private:
  int _index;
  List* _list;
};
#endif
