#ifndef __LATEX_HPP__
#define __LATEX_HPP__

#include <iostream>
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "visitor.hpp"
#include "iterator.hpp"
#include "op.hpp"
#include "base.hpp"


class Latex: public Visitor{
public:
	virtual void visit_op(Op* node){
		node->stringify() = "{" + node->stringify +"}" ;
	}
//        virtual void visit_rand(Rand* node) = 0;
/*
	virtual void visit_add_begin(Add* node) = 0;
        virtual void visit_add_middle(Add* node) = 0;
        virtual void visit_add_end(Add* node) = 0;
        virtual void visit_sub_begin(Sub* node) = 0;
        virtual void visit_sub_middle(Sub* node) = 0;
        virtual void visit_sub_end(Sub* node) = 0;
        virtual void visit_mult_begin(Mult* node) = 0;
        virtual void visit_mult_middle(Mult* node) = 0;
        virtual void visit_mult_end(Mult* node) = 0;
        virtual void visit_div_begin(Div* node) = 0;
        virtual void visit_div_middle(Div* node) = 0;
        virtual void visit_div_end(Div* node) = 0;
        virtual void visit_pow_begin(Pow* node) = 0;
        virtual void visit_pow_middle(Pow* node) = 0;
        virtual void visit_pow_end(Pow* node) = 0;

*/
};
/*
std::string PrintLaTex(Base* ptr){
	Iterarto* current = new Iterator(this);
	Visitor* visit = new Latex();

	while(current->is_done() != true){
	current->current_node()->accept(visit, i);
	++i;
	current->next();
	}
}
*/
#endif
