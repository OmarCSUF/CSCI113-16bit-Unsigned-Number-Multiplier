/*
 * ANDGate.h
 *
 *  Created on: Apr 17, 2017
 *      Author: OmAr-PC2-Local
 *      CSCI113
 */

#ifndef ANDGate_H_
#define ANDGate_H_
#include "Signals.h"

class ANDGate {
private:
	Signals sig;

public:
	ANDGate();
	void setAND(Signals s){
		this->sig = s;
	}

	bool getAND(){
		return (this->sig.a && this->sig.b);
	}

};


#endif /* ANDGate_H_ */
