#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <cmath>
#include <stdexcept>

class Pow  : public Base {
    private:
        Base* val1;
        Base* val2;
    public:
        Pow(Base* num1, Base* num2) : Base() {	
			val1 = num1;
			val2 = num2;
       	 }
        virtual double evaluate() {
		if (isinf(pow(val1->evaluate(), val2->evaluate())) == true) {
			return std::nan("");	
		}
                return pow(val1->evaluate(), val2->evaluate());
        }
        virtual std::string stringify() {
                return "(" +  std::to_string(val1->evaluate()) + " ** " +  std::to_string(val2->evaluate()) + ")";
        }
	virtual int number_of_children() { return 2; }
        virtual Base* get_child(int i) {
                if (i == 0) {
                        return val1;
                }
                else {
                        return val2;
                }
        }/*
        virtual void accept(Visitor* visitor, int index) {
                Iterator* current = new Iterator(this);
                while (current->is_done() != true) {
                        if (current->current_index() == 0) { visitor->visit_pow_begin(this); }
                        if (current->current_index() == 1) { visitor->visit_pow_middle(this); }
                        if (current->current_index() == 2) { visitor->visit_pow_end(this); }
                        current->next();
                }
        }*/


};

#endif //__POW_HPP__
