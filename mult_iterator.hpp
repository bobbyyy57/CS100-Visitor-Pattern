#ifndef	__MULT_ITERATOR__
#define __MULT_ITERATOR__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "mult.hpp"
//#include "rand.hpp"
//#include "div.hpp"
//#include "base.hpp"
#include "op.hpp"

TEST(MultIterator, MultEval){
	Op* two = new Op(2);
	Op* three = new Op(3);
	Mult* test = new Mult(two, three);

	EXPECT_EQ(test->get_child(0), two);
	EXPECT_EQ(test->get_child(1), three);
	EXPECT_EQ(test->number_of_children(), 2);
}

TEST(MultIterator, Mult_Neg_Eval){
        Op* two = new Op(-2);
        Op* three = new Op(-3);
        Mult* test = new Mult(two, three);

        EXPECT_EQ(test->get_child(0), two);
        EXPECT_EQ(test->get_child(1), three);
        EXPECT_EQ(test->number_of_children(), 2);
}

#endif 
