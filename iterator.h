#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include "struct.h"
#include "list.h"
#include <queue>
#include <stack>
#include <vector>

class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term* currentItem() const = 0;
  virtual bool isDone() const = 0;
};

class BFSIterator :public Iterator{
public:
  BFSIterator(Term *n):_n(n){}
  void first(){
    Struct *s = dynamic_cast<Struct *>(_n);
    List *l = dynamic_cast<List *>(_n);
    if(s){
      it = s->createIterator();
    }else if(l){
      it = l->createIterator();
    }
    for(it->first();!(it->isDone()); it->next()){
      BFSqueue.push(it->currentItem());
    }
  }

  void next(){
    BFSqueue.pop();
    Struct *s = dynamic_cast<Struct *>(currentItem());
    List *l = dynamic_cast<List *>(currentItem());
    if(s||l){
      if(s){
        it = s->createIterator();
      }else if(l){
        it = l->createIterator();
      }
      for(it->first();!(it->isDone()); it->next()){
        BFSqueue.push(it->currentItem());
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
  Iterator *it;
  Term* _n;
};

class DFSIterator :public Iterator{
public:
  DFSIterator(Term *n):_n(n){}

    void first(){
      Struct *s = dynamic_cast<Struct *>(_n);
      List *l = dynamic_cast<List *>(_n);
      if(s){
        it = s->createIterator();
      }else if(l){
        it = l->createIterator();
      }
      for(it->first();!(it->isDone()); it->next()){
        DFSvector.push_back(it->currentItem());
      }
      while(DFSvector.size()!=0){
        DFSstack.push(DFSvector.back());
        DFSvector.pop_back();
      }
    }

    void next(){
      DFSstack.pop();
      Term* _term = currentItem();
      Struct *s = dynamic_cast<Struct *>(_term);
      List *l = dynamic_cast<List *>(_term);
      if(s||l){
        DFSstack.pop();
        if(s){
          it = s->createIterator();
        }else if(l){
          it = l->createIterator();
        }
        for(it->first();!(it->isDone()); it->next()){
          DFSvector.push_back(it->currentItem());
        }
        while( DFSvector.size()!=0 ){
          DFSstack.push(DFSvector.back());
          DFSvector.pop_back();
        }
        DFSstack.push(_term);
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
    std::vector<Term *> DFSvector;
    int isNeedToFindDeep;
    Iterator *it;
    Term* _n;
};


class NullIterator :public Iterator{
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

class StructIterator :public Iterator {
public:
  friend class Struct;
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
  StructIterator(Struct *s): _index(0), _s(s) {}
  int _index;
  Struct* _s;
};

class ListIterator :public Iterator {
public:
  friend class List;
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
  ListIterator(List *list): _index(0), _list(list) {}
  int _index;
  List* _list;
};
#endif
