#ifndef __RAND_ITERATOR_HPP__
#define __RAND_ITERATOR_HPP__

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "iterator.hpp"
#include "op.hpp"
#include <cmath>

TEST(RandIterator, Rand){
	Base* test = new Rand();
	EXPECT_EQ(test->get_child(), nullptr);

}

#endif
