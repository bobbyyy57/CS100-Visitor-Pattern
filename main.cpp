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
#include "mathML.hpp"
#include "rand.hpp"

int main() {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(1);
    Base* two = new Op(2);
 //   Base* mult = new Mult(seven, four);
    Base* add = new Div(three, four);
    Base* minus = new Pow(seven, add);
    Base* four_op = new Add(four, two); 

    	std::string str = PrintMathML(two);
   	std::cout << "MATH ML: " << endl;
  	std::cout<<  str << std::endl;

	std::cout << std::endl;
	std::cout << "LATEX: " << endl;
	std::string str1 = PrintLaTeX(minus);
        std::cout<<  str1 << std::endl;
	
	delete three;
	delete seven;
	delete two;
	delete add;
	delete minus;
	delete four_op;
	delete four;

    return 0;
}
