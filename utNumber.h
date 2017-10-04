#ifndef UTNUMBER_H
#define UTNUMBER_H
#include "number.h"

TEST(Number, first_test){
    ASSERT_TRUE(true);
}

TEST(Number, call_value_method){
    Number one(1);
    ASSERT_EQ(1,one.value());
}

TEST(Number, call_symbol_method){
    Number ten(10);
    ASSERT_EQ("10",ten.symbol());
}

TEST(Number, call_match_method) {
    Number one(1);
    Number two(2);
    ASSERT_FALSE(one.match(two));
}

TEST(Number, match_and_then_test_value_symbol) {
  Number one(1);
  Number two(2);
  EXPECT_EQ(1,one.value());
  EXPECT_EQ("1",one.symbol());
  EXPECT_FALSE(one.match(two));
  EXPECT_EQ(1,one.value());
  ASSERT_EQ("1",one.symbol());
}

#endif
