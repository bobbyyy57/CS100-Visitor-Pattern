#ifndef __LATEX_HPP__
#define __LATEX_HPP__

#include <iostream>
#include "op.hpp"
#include "rand.hpp"
#include "visitor.hpp"
#include "add.hpp"
#include "base.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "div.hpp"

using namespace std;

class Latex : public Visitor{
	private:
	std::string desire = "";
	
    public:
        virtual ~Latex() = default;

	// Nodes with no children are visited only once (index = 0)
	virtual void visit_op(Op* node) {
		desire +=  node->stringify();
	}

        virtual void visit_rand(Rand* node){
		desire += "{" + node->stringify() + "}";
	}

	// Nodes with two children are visited three times.
	// index = 0 -> begin
	// index = 1 -> middle
	// index = 2 -> end
	std::string get_desire(){
		return desire;
	}

	virtual void visit_add_begin(Add* node){
		desire += "({";
	}
        virtual void visit_add_middle(Add* node){
		desire +=  "}+{";
	}
        virtual void visit_add_end(Add* node){
		desire += "})";
	}


        virtual void visit_sub_begin(Sub* node){
		desire += "({";
	}
        virtual void visit_sub_middle(Sub* node){
		desire += "}-{";
	}
        virtual void visit_sub_end(Sub* node){
		desire += "})" ;
	}

        virtual void visit_mult_begin(Mult* node){
		desire += "({";
	}
        virtual void visit_mult_middle(Mult* node){
		desire += "}\\cdot{";
	}
        virtual void visit_mult_end(Mult* node){
		desire += "})";
	}



        virtual void visit_div_begin(Div* node){
		desire += "\\frac{";
	}
        virtual void visit_div_middle(Div* node){
		desire += "}{";
	}
        virtual void visit_div_end(Div* node){
		desire += "}";
	}

        virtual void visit_pow_begin(Pow* node){
		 desire += "({";
	}
        virtual void visit_pow_middle(Pow* node){
		 desire += "}^{";
	}
        virtual void visit_pow_end(Pow* node){
		 desire += "})";
	}

};



string PrintLaTeX(Base* ptr){
	Iterator curr(ptr);
	Latex visitor;
	std::string output = "";
	while(curr.is_done() != true){
	curr.current_node()->accept(&visitor, curr.current_index());
	curr.next();
	}

	output = output + visitor.get_desire();
	return + "${" + output + "}$";
}	

#endif
