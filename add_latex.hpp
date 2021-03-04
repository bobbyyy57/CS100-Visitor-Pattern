#ifndef __ADD_LATEX_HPP__
#define __ADD_LATEX_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include "latex.hpp"
#include "iterator.hpp"

TEST(AddLatex, Normal) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Add* test = new Add(num1, num2);
	
        EXPECT_EQ(PrintLaTeX(test), "${({1.000000}+{2.000000})}$");
}

TEST(AddLatex, MultipleAdd) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
	Base* num3 = new Op(3);
        Add* obj = new Add(num1, num2);
	Add* test = new Add(obj, num3);

        EXPECT_EQ(PrintLaTeX(test), "${({({1.000000}+{2.000000})}+{3.000000})}$");
}

TEST(AddLatex, Negative) {
        Base* num1 = new Op(-1);
        Base* num2 = new Op(-2);
        Add* test = new Add(num1, num2);

        EXPECT_EQ(PrintLaTeX(test), "${({-1.000000}+{-2.000000})}$");
}

TEST(AddLatex, Pow) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
	Base* num3 = new Op(3);
        Add* obj = new Add(num1, num2);
	Pow* test = new Pow(num3, obj);

        EXPECT_EQ(PrintLaTeX(test), "${({3.000000}^{({1.000000}+{2.000000})})}$");
}



#endif
