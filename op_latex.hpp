#ifndef __OP_LATEX_HPP__
#define __OP_LATEX_HPP__

#include "gtest/gtest.h"
#include "iterator.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "div.hpp"
#include "latex.hpp"
#include "visitor.hpp"


TEST(OpLatex, OpPrint){
        Base* test = new Op(1);
        EXPECT_EQ( PrintLaTeX(test), "${1.000000}$");
}
TEST(OpLatex, FracOp){
        Base* test = new Op(0.21);
        EXPECT_EQ( PrintLaTeX(test), "${0.210000}$");
}


#endif
