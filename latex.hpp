#ifndef __LATEX_HPP__
#define __LATEX_HPP__

#include <iostream>

class Op;
class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

class Latex : public Visitor{
    public:
     //   virtual ~Visitor() = default;

	// Nodes with no children are visited only once (index = 0)
	virtual void visit_op(Op* node) {
		node->stringify() = "{" + node->stringify() + "}";
	}
/*        virtual void visit_rand(Rand* node) = 0;

	// Nodes with two children are visited three times.
	// index = 0 -> begin
	// index = 1 -> middle
	// index = 2 -> end
	
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
*/};

std::string PrintLaTeX(Base* ptr) {

	Iterator* current = new Iterator(ptr);
	Visitor* visit = new Latex();
	int i = 0;

        while (current->is_done() != true) {
		current->current_node()->accept(visit, i);
		++i;
		current->next();
	}

	return "${" + ptr->stringify() + "}$";
}


#endif
