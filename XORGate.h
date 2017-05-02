/*
 * ORGate.h
 *
 *  Created on: Apr 17, 2017
 *      Author: OmAr-PC2-Local
 *      CSCI113
 */

#ifndef XORGate_H_
#define XORGate_H_
#include "Signals.h"

class XORGate {
private:
	Signals sig;

public:
	XORGate();
	void setXOR(Signals s){
		this->sig = s;
	}
	bool getXOR(){
		return (this->sig.getA() ^ this->sig.getB());
	}
};


#endif /* XORGate_H_ */
