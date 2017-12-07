#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "iterator.h"
TEST(iterator, StructIterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator<Term*> *itStruct = s.createIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, StructIterator2) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    List l({ &X, &two,});
    Struct s(Atom("s"), { &one, &l, &Y });
    Iterator<Term*> *itStruct = s.createIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("[X, 2]", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, nested_iterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  Struct s(Atom("s"), { &one, &t, &Y });
  Iterator<Term*> *it = s.createIterator();
  it->first();
  it->next();
  Struct *s2 = dynamic_cast<Struct *>(it->currentItem());

  Iterator<Term*> *it2 = s2->createIterator();
  it2->first();
  ASSERT_EQ("X", it2->currentItem()->symbol());
  ASSERT_FALSE(it2->isDone());
  it2->next();
  ASSERT_EQ("2", it2->currentItem()->symbol());
  ASSERT_FALSE(it2->isDone());
  it2->next();
  ASSERT_TRUE(it2->isDone());
}
TEST(iterator, ListIterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    List _l({ &X, &two });
    List l({ &one, &_l, &Y });
    Iterator<Term*> *itList = l.createIterator();
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("[X, 2]", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

TEST(iterator, ListIterator2) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    Iterator<Term*> *itList = l.createIterator();
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

TEST(iterator, NumberIterator){
  Number one(1);
  Iterator<Term*> * it = one.createIterator();
  it->first();
  ASSERT_TRUE(it->isDone());
}

TEST(iterator, AtomIterator){
  Atom john("john");
  Iterator<Term*> * it = john.createIterator();
  it->first();
  ASSERT_TRUE(it->isDone());
}

TEST(iterator, VarIterator){
  Variable X("X");
  Iterator<Term*> * it = X.createIterator();
  it->first();
  ASSERT_TRUE(it->isDone());
}

TEST(iterator, Struct_BSFIterator){
  Number one(1);
  Number two(2);
  Variable X("X");
  Variable Y("Y");
  Struct t(Atom("t"), { &X, &two });
  Struct s(Atom("s"), { &one, &t, &Y });
  Iterator<Term*> * it = s.createBFSIterator();
  it->first();
  ASSERT_EQ("1", it->currentItem()->symbol());
  ASSERT_FALSE(it->isDone());
  it->next();
  ASSERT_EQ("t(X, 2)", it->currentItem()->symbol());
  ASSERT_FALSE(it->isDone());
  it->next();
  ASSERT_EQ("Y", it->currentItem()->symbol());
  ASSERT_FALSE(it->isDone());
  it->next();
  ASSERT_EQ("X", it->currentItem()->symbol());
  ASSERT_FALSE(it->isDone());
  it->next();
  ASSERT_EQ("2", it->currentItem()->symbol());
  ASSERT_FALSE(it->isDone());
  it->next();
  ASSERT_TRUE(it->isDone());
}

TEST(iterator, Struct_DSFIterator){
  Number one(1);
  Number two(2);
  Variable X("X");
  Variable Y("Y");
  Struct t(Atom("t"), { &X, &two });
  Struct s(Atom("s"), { &one, &t, &Y });
  Iterator<Term*> * it = s.createDFSIterator();
  it->first();
  EXPECT_EQ("1", it->currentItem()->symbol());
  EXPECT_FALSE(it->isDone());
  it->next();
  EXPECT_EQ("t(X, 2)", it->currentItem()->symbol());
  EXPECT_FALSE(it->isDone());
  it->next();
  EXPECT_EQ("X", it->currentItem()->symbol());
  EXPECT_FALSE(it->isDone());
  it->next();
  EXPECT_EQ("2", it->currentItem()->symbol());
  EXPECT_FALSE(it->isDone());
  it->next();
  EXPECT_EQ("Y", it->currentItem()->symbol());
  EXPECT_FALSE(it->isDone());
  it->next();
  EXPECT_TRUE(it->isDone());
}

TEST(iterator, List_BFSIterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    Iterator<Term*> *it = l.createBFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_EQ("t(X, 2)", it->currentItem()->symbol());
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_EQ("Y", it->currentItem()->symbol());
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_EQ("X", it->currentItem()->symbol());
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_EQ("2", it->currentItem()->symbol());
    ASSERT_FALSE(it->isDone());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST(iterator, List_DFSIterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    Iterator<Term*> *it = l.createDFSIterator();
    it->first();
    EXPECT_EQ("1", it->currentItem()->symbol());
    EXPECT_FALSE(it->isDone());
    it->next();
    EXPECT_EQ("t(X, 2)", it->currentItem()->symbol());
    EXPECT_FALSE(it->isDone());
    it->next();
    EXPECT_EQ("X", it->currentItem()->symbol());
    EXPECT_FALSE(it->isDone());
    it->next();
    EXPECT_EQ("2", it->currentItem()->symbol());
    EXPECT_FALSE(it->isDone());
    it->next();
    EXPECT_EQ("Y", it->currentItem()->symbol());
    EXPECT_FALSE(it->isDone());
    it->next();
    EXPECT_TRUE(it->isDone());
}

#endif
