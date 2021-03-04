#ifndef __DIV_ITERATOR__
#define __DIV_ITERATOR__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "div.hpp"

TEST(DivIterator, DivEval){
        Op* two = new Op(2);
        Op* three = new Op(3);
        Div* test = new Div(two, three);

        EXPECT_EQ(test->get_child(0), two);
        EXPECT_EQ(test->get_child(1), three);
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(DivIterator, Div_Neg_Eval){
        Op* two = new Op(-2);
        Op* three = new Op(-3);
        Div* test = new Div(two, three);

        EXPECT_EQ(test->get_child(0), two);
        EXPECT_EQ(test->get_child(1), three);
        EXPECT_EQ(test->number_of_children(), 2);
}

#endif 
