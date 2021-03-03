#include <iostream>

#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "rand.hpp"
//#include "iterator.hpp"
//#include "visitor.hpp"
//#include "latex.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "op.hpp"

int main() {

	Base* three = new Op(3);

//	std::string test = PrintLaTex(three)
//	std::cout << test << std::endl;
	Base* seven = new Op(7);
	Base* four = new Op(4);
	Base* two = new Op(2);
	Base* mult = new Mult(seven, four);
	Base* add = new Add(three, mult);
	Base* minus = new Sub(add, two);

	std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    return 0;
}
