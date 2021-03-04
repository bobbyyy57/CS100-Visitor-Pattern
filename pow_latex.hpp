#ifndef __POW_LATEX_HPP__
#define __POW_LATEX_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include "latex.hpp"
#include "iterator.hpp"
#include "mult.hpp"
#include "rand.hpp"
#include "div.hpp"

TEST(PowLatex, Normal) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Pow* test = new Pow(num1, num2);

        EXPECT_EQ(PrintLaTeX(test), "${({1.000000}^{2.000000})}$");
}

TEST(PowLatex, MultipleSub) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Pow* obj = new Pow(num1, num2);
        Pow* test = new Pow(obj, num3);

        EXPECT_EQ(PrintLaTeX(test), "${({({1.000000}^{2.000000})}^{3.000000})}$");
}

TEST(PowLatex, Negative) {
        Base* num1 = new Op(-1);
        Base* num2 = new Op(-2);
        Pow* test = new Pow(num1, num2);

        EXPECT_EQ(PrintLaTeX(test), "${({-1.000000}^{-2.000000})}$");
}

TEST(PowLatex, RandandDiv) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Pow* obj = new Pow(num1, num2);
        Div* test = new Div(obj, num3);
	
	EXPECT_EQ(PrintLaTeX(test), "${\\frac{({1.000000}^{2.000000})}{3.000000}}$");
}

#endif
