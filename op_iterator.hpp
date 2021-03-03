#ifndef __OP_ITERATOR_HPP__
#define __OP_ITERATOR_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpIterator, Normal) {
        Base* test = new Op(4);

        EXPECT_EQ(test->get_child(0), nullptr);
        EXPECT_EQ(test->get_child(1), nullptr);
        EXPECT_EQ(test->number_of_children(), 0);
}

#endif
