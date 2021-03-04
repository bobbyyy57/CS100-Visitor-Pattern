#ifndef __DIV_MATH_HPP__
#define __DIV_MATH_HPP__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "div.hpp"
#include "latex.hpp"
#include "visitor.hpp"
#include "mathml.hpp"

TEST(DivMath, Regular){
	Base* one = new Op(1);
	Base* three = new Op(3);
	Div* test = new Div(one, three);
	EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <divide/>\n    <cn>1.000000</cn>\n    <cn>3.000000</cn>\n  </apply>\n</math>\n");
}


TEST(DivMath, Zero_Div){
	Base* zero = new Op(0);
        Base* three = new Op(3);
	Div* test = new Div(zero, three);
        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <divide/>\n    <cn>0.000000</cn>\n    <cn>3.000000</cn>\n  </apply>\n</math>\n");
}

TEST(DivMath, Mult_Div){
        Base* zero = new Op(0);
        Base* three = new Op(3);
	Div* test = new Div(zero, three);
        Div* test2 = new Div(test, three);
        EXPECT_EQ(PrintMathML(test2), "<math>\n  <apply>\n    <divide/>\n      <apply>\n        <divide/>\n        <cn>0.000000</cn>\n        <cn>3.000000</cn>\n      </apply>\n      <cn>3.000000</cn>\n    </apply>\n</math>\n");
}

#endif
