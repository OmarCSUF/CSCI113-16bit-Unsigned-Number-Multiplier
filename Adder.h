/*
 * Adder.h
 *
 *  Created on: Apr 17, 2017
 *      Author: OmAr-PC2-Local
 *      CSCI113
 */

#ifndef Adder_H_
#define Adder_H_
#include <iterator>
#include <list>
#include "Signals.h"
#include "ANDGate.h"

using namespace std;

class Adder {
private:
	bool cin;
	bool cout;
	bool sum;
	Signals sig;
public:
	Adder(Signals sig, bool cin){
		this->sig = sig;
				this->cin = cin;
		setAdder(sig,cin);};

	void setAdder(Signals sig, bool cin){
		this->sig = sig;
		this->cin = cin;
		bool tmp1 = (this->sig.a ^ this->sig.b);
		bool tmp2 = (this->sig.a && this->sig.b);
		bool tmp3 = (tmp1 && this->cin);
		this->cout = (tmp2 || tmp3);

		this->sum = (this->sig.a^this->sig.b^this->cin);


		//std::cout <<endl<< "Adder { "<< this->sig.a<<this->sig.b<<" cin:"<< this->cin<<" sum:" << this->sum << " cout:" << this->cout<<" }"<<endl ;
	}

	bool getSUM(){

    return this->sum;
	}
	bool getCout(){

	    return this->cout;
		}

};


#endif /* Adder_H_ */
