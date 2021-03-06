#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include <stdlib.h>

class Rand: public Base{

	double val = rand()%100;
    public:
	Rand(): Base(){}
	virtual double evaluate() {return val;}
	virtual std::string stringify() {return std::to_string(val);}
	virtual int number_of_children() { return 0; }
        virtual Base* get_child(int i) { return nullptr; }
	virtual void accept(Visitor* visitor, int index) {
                visitor->visit_rand(this);
        }
};
#endif //__RAND_HPP__
