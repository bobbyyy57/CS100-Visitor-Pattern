#ifndef __ADD_MATHML_HPP__
#define __ADD_MATHML_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include "mathML.hpp"
#include "iterator.hpp"

TEST(AddMathML, Normal) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Add* test = new Add(num1, num2);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <plus/>\n    <cn>1.000000</cn>\n    <cn>2.000000</cn>\n  </apply>\n</math>\n");
}

TEST(AddMathML, MultipleAdd) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Add* obj = new Add(num1, num2);
        Add* test = new Add(obj, num3);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <plus/>\n      <apply>\n        <plus/>\n        <cn>1.000000</cn>\n        <cn>2.000000</cn>\n      </apply>\n      <cn>3.000000</cn>\n    </apply>\n</math>\n");
}

TEST(AddMathML, Negative) {
        Base* num1 = new Op(-1);
        Base* num2 = new Op(-2);
        Add* test = new Add(num1, num2);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <plus/>\n    <cn>-1.000000</cn>\n    <cn>-2.000000</cn>\n  </apply>\n</math>\n");
}

TEST(AddMathML, Pow) {
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* num3 = new Op(3);
        Add* obj = new Add(num1, num2);
        Pow* test = new Pow(num3, obj);

        EXPECT_EQ(PrintMathML(test), "<math>\n  <apply>\n    <power/>\n    <cn>3.000000</cn>\n      <apply>\n        <plus/>\n        <cn>1.000000</cn>\n        <cn>2.000000</cn>\n      </apply>\n    </apply>\n</math>\n");
}



#endif
