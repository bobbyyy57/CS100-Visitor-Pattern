#ifndef __RAND_LATEX_HPP__
#define __RAND_LATEX_HPP__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "mult.hpp"
#include "op.hpp"
//#include "iterator.cpp"
#include "div.hpp"
#include "latex.hpp"
#include "visitor.hpp"


TEST(RandLatex, RandTest){
	Base* test = new Rand();
	EXPECT_TRUE((test->evaluate() <=100)&&(test->evaluate() >=0));
}


#endif
