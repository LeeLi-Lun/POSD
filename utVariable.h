#ifndef UTVARIABLE_H
#define UTVARIABLE_H
#include "include/atom.h"
#include "include/variable.h"

TEST(Variable, first_test){
  Variable X("X");
  ASSERT_EQ("X", X.symbol());

}
TEST (Variable , have_Atom_Value){
  Atom tom("tom");
  Variable X("X");
  ASSERT_TRUE(X.match(X,tom));
}
TEST (Variable , have_Number_Value){
  Number one(1);
  Variable X("X");
  ASSERT_TRUE(X.match(X,one));
  ASSERT_EQ(X.value(),one.symbol());
}
TEST (Variable , match){
  Number one(1);
  Number two(2);
  Variable X("X");
  EXPECT_TRUE(X.match(X,one));
  ASSERT_FALSE(X.match(X,two));
}
TEST (Variable , match_variable){
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  EXPECT_TRUE(X.match(X,one));
  ASSERT_TRUE(X.match(X,Y));
}

#endif