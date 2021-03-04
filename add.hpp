#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include "iterator.hpp"

class Add  : public Base {
    private:
        Base* val1;
        Base* val2;
    public:
	~Add() = default;

        Add(Base* num1, Base* num2) : Base() {
                val1 = num1;
                val2 = num2;
        }
        virtual double evaluate() {
                return val1->evaluate() + val2->evaluate();
        }
        virtual std::string stringify() {
                return "(" +  std::to_string(val1->evaluate()) + " + " +  std::to_string(val2->evaluate()) + ")";
        }
	virtual int number_of_children() { return 2; }
        virtual Base* get_child(int i) {
		if (i == 0) {
			return val1; 
		}	
		else {	
			return val2; 
		}
	}

        virtual void accept(Visitor* visitor, int index) {
		if (index == 0) { visitor->visit_add_begin(this); }
		else if (index == 1) { visitor->visit_add_middle(this); }
		else { visitor->visit_add_end(this); }
	}

};

#endif //__ADD_HPP__
