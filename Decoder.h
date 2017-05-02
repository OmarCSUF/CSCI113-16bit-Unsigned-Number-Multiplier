/*
 * Decoder.h
 *
 *  Created on: Apr 17, 2017
 *      Author: OmAr-PC2-Local
 *      CSCI113
 */

#ifndef Decoder_H_
#define Decoder_H_
#include <vector>
#include "OPcodes.h"
#include "Signals.h"
#include "ANDGate.h"

using namespace std;

class Decoder {
private:
	Signals sig;
public:
	Decoder(OPcodes op){
		setDecoder(op);
	};

	void setDecoder(OPcodes s){

		this->sig.a = s.op1;
		this->sig.b = s.op2;
	}

	vector<bool> getDecoder(){
	vector<bool> cout;
	bool tmp;
	tmp = ((!this->sig.a) && (!this->sig.b));
	cout.push_back(tmp);
	tmp = (!this->sig.a) && (this->sig.b);
	cout.push_back(tmp);
	tmp = (this->sig.a) && (!this->sig.b);
	cout.push_back(tmp);
	tmp = (this->sig.a) && (this->sig.b);
	cout.push_back(tmp);
    return cout;
	}

};


#endif /* Decoder_H_ */
