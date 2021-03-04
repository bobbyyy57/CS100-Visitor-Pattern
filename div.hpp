#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <string>
#include <cmath>

class Div: public Base{
	private:
	Base* object1;
	Base* object2;
     public:
	Div(Base* one, Base* two): Base(){  object1 = one; object2 = two;}
	~Div() = default;
	virtual double evaluate(){
	if(object2->evaluate() == 0 ){
		return (std::nan(""));
	}
	return object1->evaluate() /object2->evaluate();
	}

	virtual std::string stringify(){
	return ("(" + std::to_string(object1->evaluate()) + " / " + std::to_string(object2->evaluate()) +")");
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
	virtual void accept(Visitor* visitor, int index) {
                if (index == 0) { visitor->visit_div_begin(this); }
                else if (index == 1) { visitor->visit_div_middle(this); }
                else if (index == 2) { visitor->visit_div_end(this); }
        }

};
#endif // __DIV_HPP__
