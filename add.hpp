#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "visitor.hpp"
#include "base.hpp"
#include "latex.hpp"

class Add  : public Base {
    private:
        Base* val1 = nullptr;
        Base* val2 = nullptr;
    public:
	virtual ~Add() {}
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

	virtual int number_of_children(){
        return 2;
        }

        virtual Base* get_child(int i){
                if(i == 0){
                return val1;
                }
                if(i == 1){
                return val2;
                }
        }

	virtual void accept(Visitor* visitor, int index){
		if(index == 0){
			visit_add_begin(this);
		}
		else if(index == 1){
			visit_add_middle(this);
		}
		else{
			visit_add_end(this);
		}
	}
};

#endif //__ADD_HPP__
