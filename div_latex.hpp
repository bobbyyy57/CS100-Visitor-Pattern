#ifndef __DIV_LATEX_HPP__
#define __DIV_LATEX_HPP__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "iterator.cpp"
#include "div.hpp"
#include "latex.hpp"
#include "visitor.hpp"


TEST(DivLatex, Regular_Div){
	Base* one = new Op(1);
	Base* three = new Op(3);
	Div* test = new Div(one, three);
	EXPECT_EQ(PrintLaTeX(test), "${\\frac{1.000000}{3.000000}}$");
	
}
TEST(DivLatex, Zero_Div){
        Base* zero = new Op(0);
        Base* three = new Op(3);
        Div* test = new Div(zero, three);
        EXPECT_EQ(PrintLaTeX(test), "${\\frac{0.000000}{3.000000}}$");

}
TEST(DivLatex, Div_Div){
        Base* one = new Op(1);
        Base* three = new Op(3);
        Div* test = new Div(one, three);
	Div* test2 = new Div(test, three);
        EXPECT_EQ(PrintLaTeX(test2), "${\\frac{\\frac{1.000000}{3.000000}}{3.000000}}$");

}
TEST(DivLatex, Div_Mult){
        Base* one = new Op(1);
        Base* three = new Op(3);
        Div* test = new Div(one, three);
        Mult* test2 = new Mult(test, three);
        EXPECT_EQ(PrintLaTeX(test2), "${({\\frac{1.000000}{3.000000}}\\cdot{3.000000})}$");

}

#endif //__DIV_MATH_HPP__
