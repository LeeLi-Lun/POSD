#ifndef UTVARIABLE_H
#define UTVARIABLE_H
#include "variable.h"
#include "struct.h"

TEST(Variable, first_test){
  Variable X("X");
  ASSERT_EQ("X", X.symbol());

}
TEST (Variable , have_Atom_Value){
  Atom tom("tom");
  Variable X("X");
  ASSERT_TRUE(X.match(tom));
}
TEST (Variable , have_Number_Value){
  Number one(1);
  Variable X("X");
  ASSERT_TRUE(X.match(one));
  ASSERT_EQ(X.value(),one.symbol());
}
TEST (Variable , match){
  Number one(1);
  Number two(2);
  Variable X("X");
  EXPECT_TRUE(X.match(one));
  ASSERT_FALSE(X.match(two));
}
TEST (Variable , match_variable){
  Number one(3);
  Variable X("X");
  Variable Y("Y");
  EXPECT_TRUE(X.match(one));
  EXPECT_TRUE(X.match(Y));
  ASSERT_EQ("3",Y.value());
}

// ?- X=2.7182.
// X=2.7182
TEST(Variable , numE_to_varX){
  Number num1(2.7182);
  Variable X("X");
  EXPECT_TRUE(X.match(num1));
  EXPECT_EQ( "2.7182",X.value() );
  ASSERT_EQ(X.value(),num1.value());
}

// ?- X=Y, X=1.
// Y=1
TEST (Variable, varY_to_varX_and_num1_to_varX) {
  Number num1(1);
  Variable X("X");
  Variable Y("Y");
  EXPECT_TRUE(X.match(Y));
  EXPECT_TRUE(X.match(num1));
  ASSERT_EQ("1",Y.value());
}

// ?- X=Y, Y=1.
// X=1
TEST (Variable, varY_to_varX_and_num1_to_varY) {
  Number num1(1);
  Variable X("X");
  Variable Y("Y");
  EXPECT_TRUE(X.match(Y));
  EXPECT_TRUE(Y.match(num1));
  ASSERT_EQ("1",X.value());
}

// ?- X=X, X=1.
// X=1
TEST (Variable, varX_match_varX_and_num1_to_varX) {
  Number num1(1);
  Variable X("X");
  EXPECT_TRUE(X.match(X));
  EXPECT_TRUE(X.match(num1));
  ASSERT_EQ("1",X.value());
}

// ?- Y=1, X=Y.
// X=1
TEST (Variable, num1_to_varY_and_varX_match_varY) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  EXPECT_TRUE(Y.match(one));
  EXPECT_TRUE(X.match(Y));
  ASSERT_EQ("1",X.value());
}

// ?- X=Y, Y=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varY_to_varX) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Variable Z("Z");
  EXPECT_TRUE(X.match(Y));
  EXPECT_TRUE(Y.match(Z));
  EXPECT_TRUE(Z.match(one));
  EXPECT_EQ("1",X.value());
  EXPECT_EQ("1",Y.value());
  ASSERT_EQ("1",Z.value());
}

// ?- X=Y, X=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varX_and_varY_to_varX) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Variable Z("Z");
  EXPECT_TRUE(X.match(Y));
  EXPECT_TRUE(X.match(Z));
  EXPECT_TRUE(Z.match(one));
  EXPECT_EQ("1",X.value());
  EXPECT_EQ("1",Y.value());
  ASSERT_EQ("1",Z.value());
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(X)"
TEST (Variable, Struct1) {
  Variable X("X");
  Variable Y("Y");
  std::vector<Term *> v = {&X};
  Struct s(Atom("s"), v);
  Y.match(s);
  EXPECT_EQ("Y",Y.symbol());
  EXPECT_EQ("s(X)",Y.value());
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// And X matches Atom "teddy"
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(teddy)"
TEST (Variable, Struct2) {
  Variable X("X");
  Variable Y("Y");
  Atom teddy("teddy");
  std::vector<Term *> v = {&X};
  Struct s(Atom("s"), v);
  X.match(teddy);
  Y.match(s);

  EXPECT_EQ("Y",Y.symbol());
  EXPECT_EQ("s(teddy)",Y.value());
}

#endif
