/*
 * Mux4x1.h
 *
 *  Created on: Apr 17, 2017
 *      Author: OmAr-PC2-Local
 *      CSCI113
 */

#ifndef Mux4x1_H_
#define Mux4x1_H_
#include <vector>
#include "Decoder.h"
#include "Signals.h"
#include "ANDGate.h"
#include "ORGate.h"


using namespace std;

class Mux4x1 {
private:
	OPcodes ops;
	vector<bool> lst;

public:
	Mux4x1(OPcodes op,vector<bool> lst)
{
		this->ops = op;
		this->lst = lst;
		setMux4x1(op, lst);
};

	void setMux4x1(OPcodes op,vector<bool> lst){
		this->ops = op;
		this->lst = lst;

	}

	bool getMux4x1(){
		Decoder decoder(this->ops);
		vector<bool> decoRes = decoder.getDecoder();
		/*
		cout <<"Dec of "<<this->ops.op1<<this->ops.op2<<": ";
		for(int i=0;i<4;++i){
		cout<<decoRes[i]<< " ";
		}

		cout <<endl;
		*/
		bool tmpRes;
		vector<bool> and_temp;
		bool cOut;

		tmpRes = (this->lst[0]&&decoRes[0]);
		and_temp.push_back(tmpRes);

		tmpRes = (this->lst[1]&&decoRes[1]);
		and_temp.push_back(tmpRes);

		tmpRes = (this->lst[2]&&decoRes[2]);
		and_temp.push_back(tmpRes);

		tmpRes = (this->lst[3]&&decoRes[3]);
		and_temp.push_back(tmpRes);


		cOut = (and_temp[0] || and_temp[1] ||and_temp[2] || and_temp[3]);
		and_temp.empty();
		and_temp.clear();


		return cOut;
	}

};


#endif /* Mux4x1_H_ */
