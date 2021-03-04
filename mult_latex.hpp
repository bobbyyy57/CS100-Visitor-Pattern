#ifndef __MULT_LATEX_HPP__
#define __MULT_LATEX_HPP__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "mult.hpp"
#include "op.hpp"
//#include "iterator.cpp"
#include "div.hpp"
#include "latex.hpp"
#include "visitor.hpp"


TEST(MultLatex, Regular_Mult){
        Base* one = new Op(1);
        Base* three = new Op(3);
        Mult* test = new Mult(one, three);
        EXPECT_EQ(PrintLaTeX(test), "${({1.000000}\\cdot{3.000000})}$");

}
TEST(MultLatex, Zero_Mult){
        Base* zero = new Op(0);
        Base* three = new Op(3);
        Mult* test = new Mult(zero, three);
        EXPECT_EQ(PrintLaTeX(test), "${({0.000000}\\cdot{3.000000})}$");

}

TEST(MultLatex, Mult_Mult){
        Base* zero = new Op(0);
        Base* three = new Op(3);
        Mult* test = new Mult(zero, three);
	Mult* test2 = new Mult(test, three);
        EXPECT_EQ(PrintLaTeX(test2), "${({({0.000000}\\cdot{3.000000})}\\cdot{3.000000})}$");

}

TEST(MultLatex, Big_Mult){
        Base* zero = new Op(10000);
        Base* three = new Op(311);
        Mult* test = new Mult(zero, three);
        Mult* test2 = new Mult(test, three);
        EXPECT_EQ(PrintLaTeX(test2), "${({({10000.000000}\\cdot{311.000000})}\\cdot{311.000000})}$");

}


#endif
