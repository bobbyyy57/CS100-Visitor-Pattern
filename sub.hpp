#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Sub  : public Base {
    private:
        Base* val1;
        Base* val2;
    public:
        Sub(Base* num1, Base* num2) : Base() {
                val1 = num1;
                val2 = num2;
        }
        virtual double evaluate() {
                return val1->evaluate() - val2->evaluate();
        }
        virtual std::string stringify() {
                return "(" +  std::to_string(val1->evaluate()) + " - " +  std::to_string(val2->evaluate()) + ")";
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
                if (index == 0) { visitor->visit_sub_begin(this); }
                else if (index == 1) { visitor->visit_sub_middle(this); }
                else if (index == 2) { visitor->visit_sub_end(this); }
        }

};

#endif //__SUB_HPP__
