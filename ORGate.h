/*
 * ORGate.h
 *
 *  Created on: Apr 17, 2017
 *      Author: OmAr-PC2-Local
 *      CSCI113
 */

#ifndef ORGate_H_
#define ORGate_H_
#include "Signals.h"

class ORGate {
private:
	Signals sig;

public:
	ORGate();
	void setOR(Signals s){
		this->sig = s;
	}

	bool getOR(){
		return ((this->sig.a || this->sig.b));
	}

};


#endif /* ORGate_H_ */
