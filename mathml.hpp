#ifndef __MATH_HPP__
#define __MATH_HPP__
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

class MathML : public Visitor{
	private:
	std::string space = "";
        public:
        int count = 0; 
        ~MathML(){}; 

        void plus(){
                count++; 
        }

        void minus(){
                count--; 
        }

	std::string get_space(){
		return space;
	}
	
        void tab(){
                for(int i = 0; i < count; ++i){
                        space += "  ";
                }
        }

	virtual void visit_op(Op* node){
		tab();
		space += "<cn>" + node->stringify() + "</cn>\n";
	}
        virtual void visit_rand(Rand* node){
		tab();
                space += "<cn>" + node->stringify() + "</cn>\n"	;
	}



        virtual void visit_add_begin(Add* node){
		plus();
		tab();
		space += "<apply>\n";
		plus();
		tab();
		space += "<plus/>\n";
	}
        virtual void visit_add_middle(Add* node){}
        virtual void visit_add_end(Add* node){
		minus();
		tab();
		space += "</apply>\n";
	}

        virtual void visit_sub_begin(Sub* node){
		plus();
                tab();
                space += "<apply>\n";
                plus();
                tab();
                space += "<minus/>\n";
	}
        virtual void visit_sub_middle(Sub* node){}
        virtual void visit_sub_end(Sub* node){
		minus();
                tab();
                space += "</apply>\n";
	}
        virtual void visit_mult_begin(Mult* node){
		plus();
                tab();
                space += "<apply>\n";
                plus();
                tab();
                space += "<times/>\n";
	}
        virtual void visit_mult_middle(Mult* node){}
        virtual void visit_mult_end(Mult* node){
		minus();
                tab();
                space += "</apply>\n";
	}
        virtual void visit_div_begin(Div* node){
		plus();
                tab();
                space += "<apply>\n";
                plus();
                tab();
                space += "<divide/>\n";
	}
        virtual void visit_div_middle(Div* node){}
        virtual void visit_div_end(Div* node){
		minus();
                tab();
                space += "</apply>\n";
	}
        virtual void visit_pow_begin(Pow* node){
		plus();
                tab();
                space += "<apply>\n";
                plus();
                tab();
                space += "<power/>\n";
	}
        virtual void visit_pow_middle(Pow* node){}
        virtual void visit_pow_end(Pow* node){
		minus();
                tab();
                space += "</apply>\n";
	}
};

	std::string PrintMathML(Base* ptr){
   		Iterator curr(ptr);
    		MathML visit;
    		std::string output;

		while (!curr.is_done()){
        		curr.current_node()->accept(&visit,curr.current_index());
		        curr.next();
		    }
	    output = output + visit.get_space();
	    return "<math>\n" + output + "</math>\n";
}


#endif
