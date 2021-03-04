#ifndef __POW_ITERATOR_HPP__
#define __POW_ITERATOR_HPP__

#include "gtest/gtest.h"

#include "pow.hpp"
#include "op.hpp"

TEST(PowIterator, Normal) {
        Base* num1 = new Op(4);
        Base* num2 = new Op(6);
        Pow* test = new Pow(num1, num2);

        EXPECT_EQ(test->get_child(0), num1);
        EXPECT_EQ(test->get_child(1), num2);
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(PowIterator, Negative) {
        Base* num1 = new Op(-4);
        Base* num2 = new Op(-6);
        Pow* test = new Pow(num1, num2);

        EXPECT_EQ(test->get_child(0), num1);
        EXPECT_EQ(test->get_child(1), num2);
        EXPECT_EQ(test->number_of_children(), 2);
}

#endif
