#ifndef __SUB_MATHML_HPP__
#define __SUB_MATHML_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include "latex.hpp"
#include "iterator.hpp"
#include "mult.hpp"

TEST(SubMathML, Normal) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Sub* test = new Sub(num1, num2);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <minus/>\n    <cn>1.000000</cn>\n    <cn>2.000000</cn>\n  </apply>\n</math>\n");
}

TEST(SubMathML, MultipleSub) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Sub* obj = new Sub(num1, num2);
        Sub* test = new Sub(obj, num3);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <minus/>\n      <apply>\n        <minus/>\n        <cn>1.000000</cn>\n        <cn>2.000000</cn>\n      </apply>\n      <cn>3.000000</cn>\n    </apply>\n</math>\n");
}

TEST(SubMathML, Negative) {
        Base* num1 = new Op(-1);
        Base* num2 = new Op(-2);
        Sub* test = new Sub(num1, num2);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <minus/>\n    <cn>-1.000000</cn>\n    <cn>-2.000000</cn>\n  </apply>\n</math>\n");
}

TEST(SubMathML, Mult) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Sub* obj = new Sub(num1, num2);
        Mult* test = new Mult(num3, obj);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <times/>\n    <cn>3.000000</cn>\n      <apply>\n        <minus/>\n        <cn>1.000000</cn>\n        <cn>2.000000</cn>\n      </apply>\n    </apply>\n</math>\n");
}

#endif
