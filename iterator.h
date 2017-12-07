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
      BFSqueue.push(it->currentItem());
    }
    Iterator<Term*> *it2 = BFSqueue.front()->createIterator();
    if(!(it2->isDone())){
      for(it2->first();!(it2->isDone()); it2->next()){
        BFSqueue.push(it2->currentItem());
      }
    }
  }

  void next(){
    BFSqueue.pop();
    if(BFSqueue.size()!= 0 ){
      Iterator<Term*> *it = currentItem()->createIterator();
      if(it->currentItem()!=nullptr){
        for(it->first();!(it->isDone()); it->next()){
          BFSqueue.push(it->currentItem());
        }
      }
    }
  }

  Term * currentItem() const{
    return BFSqueue.front();
  }

  bool isDone() const{
    return BFSqueue.empty();
  }

  private:
  std::queue<Term *> BFSqueue;
  Term* _n;
};

class DFSIterator :public Iterator<Term*>{
public:
  DFSIterator(Term *n):_n(n){}

  void first(){
    Iterator<Term*> *it = _n->createIterator();
    Term* _term = it->currentItem();
    for(it->first();!(it->isDone()); it->next()){
      Tempvector.push_back(it->currentItem());
    }
    while(Tempvector.size()!=0){
      DFSstack.push(Tempvector.back());
      Tempvector.pop_back();
    }
    Iterator<Term*> *it2 = DFSstack.top()->createIterator();
    if(!(it2->isDone())){
      DFSstack.pop();
      for(it2->first();!(it2->isDone()); it2->next()){
        Tempvector.push_back(it2->currentItem());
      }
      while(Tempvector.size()!=0){
        DFSstack.push(Tempvector.back());
        Tempvector.pop_back();
      }
      DFSstack.push(_term);
     }
  }

  void next(){
    DFSstack.pop();
    if(DFSstack.size()!= 0 ){
      Term* _term = currentItem();
      Iterator<Term*> *it = _term->createIterator();
      if(it->currentItem()!=nullptr){
        DFSstack.pop();
        for(it->first();!(it->isDone()); it->next()){
          Tempvector.push_back(it->currentItem());
        }
        //std::reverse(Tempvector.begin(),Tempvector.end());
        while(Tempvector.size()!=0){
          DFSstack.push(Tempvector.back());
          Tempvector.pop_back();
        }
        DFSstack.push(_term);
      }
    }
  }

  Term * currentItem() const{
    return DFSstack.top();
  }

  bool isDone() const{
    return DFSstack.empty();
  }

private:
  std::stack<Term *> DFSstack;
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
