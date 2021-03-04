#ifndef __OP_MATH_HPP__
#define __OP_MATH_HPP__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "div.hpp"
#include "latex.hpp"
#include "visitor.hpp"
#include "mathml.hpp"


TEST(OpMath, OpPrint){
        Base* test = new Op(1);
        EXPECT_EQ( PrintMathML(test), "<math>\n<cn>1.000000</cn>\n</math>\n");
}
TEST(OpMath, FracOp){
        Base* test = new Op(0.21);
        EXPECT_EQ( PrintMathML(test), "<math>\n<cn>0.210000</cn>\n</math>\n");
}


#endif
