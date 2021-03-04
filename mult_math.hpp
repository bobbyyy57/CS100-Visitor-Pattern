#ifndef __MULT_MATH_HPP__
#define __MULT_MATH_HPP__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "div.hpp"
#include "latex.hpp"
#include "visitor.hpp"
#include "mathml.hpp"

TEST(MultMath, Regular){
        Base* one = new Op(1);
        Base* three = new Op(3);
        Div* test = new Div(one, three);
        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <divide/>\n    <cn>1.000000</cn>\n    <cn>3.000000</cn>\n  </apply>\n</math>\n");
}


TEST(MultMath, Zero_Mult){
        Base* zero = new Op(0);
        Base* three = new Op(3);
        Mult* test = new Mult(zero, three);
        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <times/>\n    <cn>0.000000</cn>\n    <cn>3.000000</cn>\n  </apply>\n</math>\n");
}

TEST(MultMath, Mult_Div){
        Base* zero = new Op(0);
        Base* three = new Op(3);
        Mult* test = new Mult(zero, three);
        Mult* test2 = new Mult(test, three);
        EXPECT_EQ(PrintMathML(test2), "<math>\n  <apply>\n    <times/>\n      <apply>\n        <times/>\n        <cn>0.000000</cn>\n        <cn>3.000000</cn>\n      </apply>\n      <cn>3.000000</cn>\n    </apply>\n</math>\n");
}

#endif
