#ifndef __RAND_ITERATOR_HPP__
#define __RAND_ITERATOR_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"
#include <cmath>

TEST(RandIterator, Normal) {
 
	Rand* test = new Rand();

        EXPECT_EQ(test->get_child(0), nullptr);
        EXPECT_EQ(test->get_child(1), nullptr);
        EXPECT_EQ(test->number_of_children(), 0);
}

#endif
~              
