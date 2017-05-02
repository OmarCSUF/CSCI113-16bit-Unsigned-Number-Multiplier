/*
 * ALU.h
 *
 *  Created on: Apr 17, 2017
 *      Author: OmAr-PC2-Local
 *      CSCI113
 */

#ifndef ALU_H_
#define ALU_H_
#include <vector>
#include <algorithm>
#include "Signals.h"
#include "Adder.h"
#include "Mux4x1.h"


using namespace std;

class ALU {
private:
	Signals sig;
	OPcodes ops;
	vector<bool> resLst;
	vector<bool> fstInputLst;
	vector<bool> secInputLst;
	bool bINV;
	bool oF;
	bool cIn;
	bool cOut;
	void setALU(){
		ALU_Manager();
		//if(this->bINV == true)


	}
	void ALU_Manager(){
		this->cIn = bINV;
		bool tmp;
		Signals s;
		for (int i = this->fstInputLst.size()-1; i > 0; --i) {
			s.a = this->fstInputLst[i];
			s.b = this->secInputLst[i];

			if(this->bINV == true){
				s.b = !s.b;
			}
			tmp = Alu1bit(s);
			//cout<<i<<": "<<s.a << " + " <<s.b<<" = "<< tmp<<"  cout= "<<this->cOut<<endl;
			resLst.push_back(tmp);
		}

		s.a = this->fstInputLst[0];
		s.b = this->secInputLst[0];
		tmp = Alu1bitWithOf(s);
		//cout<<"0"<<": "<<s.a << " + " <<s.b<<" = "<<tmp<<endl;
		resLst.push_back(tmp);
	}

	bool Alu1bit(Signals s){

		vector<bool> muxInputs;


		muxInputs.push_back((s.a && s.b));
		muxInputs.push_back((s.a || s.b));
		Adder adder(s,this->cIn);

		muxInputs.push_back(adder.getSUM());
		this->cOut = adder.getCout();
		this->cIn = this->cOut;

		Mux4x1 mux(this->ops, muxInputs);
		bool xx = mux.getMux4x1();


		return xx;
	}

	bool Alu1bitWithOf(Signals s){

		vector<bool> muxInputs;

		if(this->bINV == true)
			s.b = !s.b;
		muxInputs.push_back((s.a && s.b));
		muxInputs.push_back((s.a || s.b));

		Adder adder(s,this->cIn);

		bool adderRes = adder.getSUM();
		muxInputs.push_back(adderRes);
		bool tmp1 = (s.a ^ s.b);
		bool tmp2 = (s.a ^ adderRes);
		this->oF = (!tmp1 && tmp2);

		Mux4x1 mux(this->ops,muxInputs);

		return mux.getMux4x1();
	}


public:
	ALU(vector<bool> input1,vector<bool> input2,OPcodes op)
{
		this->fstInputLst = input1;
		this->secInputLst = input2;
		if((op.op1 == true && op.op2 == true))
		{
			this->bINV = true;
			cIn = true;
		}
		else
		{
			this->bINV = false;
			cIn = false;
		}
		this->ops = op;
		setALU();

};


	vector<bool> getALU(){
		reverse(this->resLst.begin(), this->resLst.end());
		return this->resLst;
	}

	bool getOF(){
		return this->oF;
	}



};


#endif /* ALU_H_ */
