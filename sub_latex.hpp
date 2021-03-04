#ifndef __SUB_LATEX_HPP__
#define __SUB_LATEX_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include "latex.hpp"
#include "iterator.hpp"
#include "mult.hpp"

TEST(SubLatex, Normal) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Sub* test = new Sub(num1, num2);

        EXPECT_EQ(PrintLaTeX(test), "${({1.000000}-{2.000000})}$");
}

TEST(SubLatex, MultipleSub) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Sub* obj = new Sub(num1, num2);
        Sub* test = new Sub(obj, num3);

        EXPECT_EQ(PrintLaTeX(test), "${({({1.000000}-{2.000000})}-{3.000000})}$");
}

TEST(SubLatex, Negative) {
        Base* num1 = new Op(-1);
        Base* num2 = new Op(-2);
        Sub* test = new Sub(num1, num2);

        EXPECT_EQ(PrintLaTeX(test), "${({-1.000000}-{-2.000000})}$");
}

TEST(SubLatex, Mult) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Sub* obj = new Sub(num1, num2);
        Mult* test = new Mult(num3, obj);

        EXPECT_EQ(PrintLaTeX(test), "${({3.000000}\\cdot{({1.000000}-{2.000000})})}$");
}

#endif
