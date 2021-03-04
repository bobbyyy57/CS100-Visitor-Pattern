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
#include "mathml.hpp"

int main() {
	Base* three = new Op(3);
	Base* four = new Op(4);
	Base* seven = new Op(7);
	Base* rand = new Rand();

	Base* test = new Div(three, four);
	Base* test2 = new Div(three, test);
	Base* mult = new Mult(three, test);
	Base* test3 = new Div(test, seven);
   
    	std::string str = PrintMathML(test);
    	std::string str2 =PrintMathML(mult);
	std::string str3 =PrintMathML(rand);
    	std::string str4 =PrintLaTeX(test);
    	std::string str5 =PrintLaTeX(test2);
    	std::string str6 =PrintLaTeX(test3);

    std::cout << str << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    std::cout << str4 << std::endl;
    std::cout << str5 << std::endl;
    std::cout << str6 << std::endl;

    return 0;
}
