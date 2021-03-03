#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <string>
#include <cmath>

class Mult : public Base{
	private:
	Base* object1;
	Base* object2;
    public:
	Mult(Base* a, Base* b): Base(){object1 = a; object2 = b;}
	virtual double evaluate(){
		if(isinf(object1->evaluate() * object2->evaluate())){
			return std::nan("");
		}
		return (object1->evaluate() * object2->evaluate());
    	}
	virtual std::string stringify(){
		return ("("+ std::to_string(object1->evaluate()) + " * "+ std::to_string(object2->evaluate())+")");
   	 }
	virtual int number_of_children() { return 2; }
        virtual Base* get_child(int i) {
                if (i == 0) {
                        return object1;
                }
                else {
                        return object2;
                }
        }
/*
        virtual void accept(Visitor* visitor, int index) {
                Iterator* current = new Iterator(this);
                while (current->is_done() != true) {
                        if (current->current_index() == 0) { visitor->visit_mult_begin(this); }
                        if (current->current_index() == 1) { visitor->visit_mult_middle(this); }
                        if (current->current_index() == 2) { visitor->visit_mult_end(this); }
                        current->next();
                }
        }
*/

};
#endif //__MULT_HPP__
