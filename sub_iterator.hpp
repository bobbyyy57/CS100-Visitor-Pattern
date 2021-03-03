#ifndef __SUB_ITERATOR_HPP__
#define __SUB_ITERATOR_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "op.hpp"

TEST(SubIterator, Normal) {
        Base* num1 = new Op(4);
        Base* num2 = new Op(6);
        Sub* test = new Sub(num1, num2);

        EXPECT_EQ(test->get_child(0), num1);
        EXPECT_EQ(test->get_child(1), num2);
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(SubIterator, Negative) {
        Base* num1 = new Op(-4);
        Base* num2 = new Op(-6);
        Sub* test = new Sub(num1, num2);

        EXPECT_EQ(test->get_child(0), num1);
        EXPECT_EQ(test->get_child(1), num2);
        EXPECT_EQ(test->number_of_children(), 2);
}

#endif
