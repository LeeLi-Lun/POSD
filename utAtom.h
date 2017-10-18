#ifndef UTATOM_H
#define UTATOM_H
#include "atom.h"

TEST(Atom, firs_test) {
  ASSERT_TRUE(true);
}

TEST(Atom, call_symbol_method) {
  Atom tom("tom");
  ASSERT_EQ("tom",tom.symbol());
}

TEST(Atom, call_value_method) {
  Atom john("john");
  ASSERT_EQ("john",john.value());
}

TEST(Atom, call_match_method) {
  Atom tom("tom");
  Atom john("john");
  ASSERT_FALSE(tom.match(john));
}

TEST(Atom, match_and_then_test_value_symbol) {
  Atom tom("tom");
  Atom john("john");
  EXPECT_EQ("tom",tom.value());
  EXPECT_EQ("tom",tom.symbol());
  EXPECT_FALSE(tom.match(john));
  EXPECT_EQ("tom",tom.value());
  ASSERT_EQ("tom",tom.symbol());
}

#endif
