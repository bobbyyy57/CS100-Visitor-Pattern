#ifndef __LATEX_HPP__
#define __LATEX_HPP__

#include <iostream>
#include "rand.hpp"
class Op;
//class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

using namespace std;

class Latex : public Visitor{
    private: 
	string desired;
    public:
         ~Latex() = default;

	// Nodes with no children are visited only once (index = 0)
	virtual void visit_op(Op* node) {
		desired += node->stringify();
	}
        virtual void visit_rand(Rand* node) {
		desired += node->stringify();
	}
	string getDesired() { return desired; }
	void append(string s) { desired += s; }
  
	// Nodes with two children are visited three times.
	// index = 0 -> begin
	// index = 1 -> middle
	// index = 2 -> end
	
	virtual void visit_add_begin(Add* node) {
		append("({");	
	}
        virtual void visit_add_middle(Add* node) {
		append("}+{");
	}
        virtual void visit_add_end(Add* node) {
		append("})");
	}
	virtual void visit_sub_begin(Sub* node) {
		append("({");
	}
        virtual void visit_sub_middle(Sub* node) {
		append("}-{");
	}
        virtual void visit_sub_end(Sub* node) {
        	append("})");
	}
        virtual void visit_mult_begin(Mult* node) {
		append("({");
	}
        virtual void visit_mult_middle(Mult* node) {
		append("}\\cdot{");
	}
        virtual void visit_mult_end(Mult* node) {
		append("})");
	}
        virtual void visit_div_begin(Div* node) {
		append("\\frac{");	
	}
        virtual void visit_div_middle(Div* node) {
		append("}{");
	}
        virtual void visit_div_end(Div* node) {
		append("}");
	}
        virtual void visit_pow_begin(Pow* node) {
		append("({");
	}
        virtual void visit_pow_middle(Pow* node) {
		append("}^{");		
	}
        virtual void visit_pow_end(Pow* node) {
		append("})");
	}
};

std::string PrintLaTeX(Base* ptr) {
	Iterator curr(ptr);
	Latex visit;
	string wanted = "";
	while (curr.is_done() != true) {
		curr.current_node()->accept(&visit, curr.current_index());
		curr.next();
	}
	wanted += visit.getDesired();

	return "${" + wanted + "}$";
}

#endif
