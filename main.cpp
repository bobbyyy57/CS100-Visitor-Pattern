#include <iostream>
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include "iterator.cpp"
#include "latex.hpp"

int main() {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
//    Base* mult = new Mult(seven, four);
  //  Base* add = new Add(three, mult);
   // Base* minus = new Sub(add, two);

//    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
   
    std::string str = PrintLaTeX(three);   
    std::cout << str;

    return 0;
}
