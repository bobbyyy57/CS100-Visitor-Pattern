#ifndef __ADD_ITERATOR_HPP__
#define __ADD_ITERATOR_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "op.hpp"
#include "iterator.cpp"

TEST(AddIterator, Normal) {
	Base* num1 = new Op(4);
	Base* num2 = new Op(6);
	Add* test = new Add(num1, num2);
	
	EXPECT_EQ(test->get_child(0), num1);		
    	EXPECT_EQ(test->get_child(1), num2);
	EXPECT_EQ(test->number_of_children(), 2);
}

TEST(AddIterator, Negative) {
        Base* num1 = new Op(-4);
        Base* num2 = new Op(-6);
        Add* test = new Add(num1, num2);

        EXPECT_EQ(test->get_child(0), num1);
        EXPECT_EQ(test->get_child(1), num2);
        EXPECT_EQ(test->number_of_children(), 2);
}


#endif
