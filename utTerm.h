#ifndef UTTERM_H
#define UTTERM_H
#include "include/atom.h"
#include "include/number.h"
#include "include/variable.h"

//test Number.value()
TEST (Number,ctor) {
  Number one(1);
  ASSERT_EQ(1,one.value());
}

//test Number.symbol()
TEST (Number, symbol) {
  Number one(1);
  ASSERT_EQ("1",one.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
  Number twenty_five(25);
  Number twenty_five2(25);
  ASSERT_TRUE(twenty_five.match(twenty_five,twenty_five2));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
  Number twenty_five(25);
  Number zero(0);
  ASSERT_FALSE(twenty_five.match(twenty_five,zero));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
  Number twenty_five(25);
  Atom tom("tom");
  ASSERT_FALSE(twenty_five.match(twenty_five,tom));
}


//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
  Number twenty_five(25);
  Variable X("X");
  EXPECT_TRUE(twenty_five.match(twenty_five,X));
  ASSERT_EQ("25",X.value());
}


//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
  Atom tom("tom");
  Number twenty_five(25);
  ASSERT_FALSE(tom.match(tom,twenty_five));
}


// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
  Atom tom("tom");
  Variable X("X");
  EXPECT_TRUE(tom.match(tom,X));
  ASSERT_EQ("tom",X.value());
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
  Atom tom("tom");
  Variable X("X");
  EXPECT_TRUE(X.match(X,tom));
  EXPECT_TRUE(tom.match(tom,X));
  ASSERT_EQ("tom",X.value());
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
  Atom jerry("jerry");
  Atom tom("tom");
  Variable X("X");
  EXPECT_TRUE(X.match(X,jerry));
  ASSERT_FALSE(tom.match(tom,X));
}

// ?- X = 5.
// X = 5.
TEST (Variable, matchSuccessToNumber) {
  Variable X("X");
  Number five(5);
  EXPECT_TRUE(X.match(X,five));
  ASSERT_EQ("5",X.value());
}

// ?- X=25, X= 100.
// false.
TEST (Variable, matchFailureToTwoDiffNumbers) {
  Variable X("X");
  Number twenty_five(25);
  Number hundred(100);
  EXPECT_TRUE( X.match(X,twenty_five) );
  ASSERT_FALSE( X.match(X,hundred) );
}

// ?- X=tom, X= 25.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber) {
  Variable X("X");
  Atom tom("tom");
  Number twenty_five(25);
  EXPECT_TRUE( X.match(X,tom) );
  ASSERT_FALSE( X.match(X,twenty_five) );
}
//?- tom=X, 25=X.
//false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber2) {
  Variable X("X");
  Atom tom("tom");
  Number twenty_five(25);
  EXPECT_TRUE( tom.match(tom,X) );
  ASSERT_FALSE( twenty_five.match(twenty_five,X) );
}

//?- X=tom, X=tom.
//true.
TEST(Variable, reAssignTheSameAtom){
  Variable X("X");
  Atom tom("tom");
  EXPECT_TRUE( X.match(X,tom) );
  ASSERT_TRUE( X.match(X,tom) );
}

#endif
