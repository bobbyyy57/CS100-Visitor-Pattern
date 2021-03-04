#ifndef __POW_MATHML_HPP__
#define __POW_MATHML_HPP__

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

TEST(PowMathML, Normal) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Pow* test = new Pow(num1, num2);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <power/>\n    <cn>1.000000</cn>\n    <cn>2.000000</cn>\n  </apply>\n</math>\n");
}

TEST(PowMathML, MultipleSub) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Pow* obj = new Pow(num1, num2);
        Pow* test = new Pow(obj, num3);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <power/>\n      <apply>\n        <power/>\n        <cn>1.000000</cn>\n        <cn>2.000000</cn>\n      </apply>\n      <cn>3.000000</cn>\n    </apply>\n</math>\n");
}

TEST(PowMathML, Negative) {
        Base* num1 = new Op(-1);
        Base* num2 = new Op(-2);
        Pow* test = new Pow(num1, num2);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <power/>\n    <cn>-1.000000</cn>\n    <cn>-2.000000</cn>\n  </apply>\n</math>\n");
}

TEST(PowMathML, RandandDiv) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Pow* obj = new Pow(num1, num2);
        Div* test = new Div(obj, num3);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <divide/>\n      <apply>\n        <power/>\n        <cn>1.000000</cn>\n        <cn>2.000000</cn>\n      </apply>\n      <cn>3.000000</cn>\n    </apply>\n</math>\n");
}

#endif
