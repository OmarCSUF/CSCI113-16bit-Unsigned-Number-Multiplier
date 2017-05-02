//============================================================================
// Name        : CSCI113_ALU.cpp
// Author      : Omar
// Version     :
// Copyright   : 
// Description :  C++, Ansi-style
//============================================================================


#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "ALU.h"
#include "OPcodes.h"


using namespace std;
 OPcodes ops;

void Multiplier(vector<bool>& MD,vector<bool>& MQ);
void ShiftingZero(vector<bool> &vec1,vector<bool> &vec2)	;
int main() {
	ops.op1 =1;
	ops.op2 =0;


	static const bool arr1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0};
	static const bool arr2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0};
	vector<bool> a (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
	vector<bool> b (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

	//ALU a1(a,b,ops);
	//list<bool> input1,list<bool> input2,OPcodes op
	//vector<bool> res = a1.getALU();
	cout<<"n                  "<<"  MD     "<<"                     AC"<<"                              MQ    "<<endl;
for(int i =0; i<54 ; ++i)
	cout<<"--";

cout<<endl;

	Multiplier(a,b);

	return 0;
}

void Multiplier(vector<bool>& MD,vector<bool>& MQ){
	static const bool arr1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector<bool> AC (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
	AC = MD;
	vector<bool> ACa= MD;

	for(int i=0; i<MD.size();++i ){
		if (i<10)
		cout << i<< "   ";
		else
			cout << i<< "  ";
		if(MQ.back()==1){
			ALU a1(AC,MD,ops);
			AC = a1.getALU();
			ShiftingZero(AC,MQ);
					}


		else{
			ShiftingZero(AC,MQ);

		}

		for(vector<bool>::iterator it = MD.begin(); it!= MD.end(); ++it) {
			bool boo = *it;
			cout << boo << " ";
		}
		cout << "  ";
		for(vector<bool>::iterator it = AC.begin(); it!= AC.end(); ++it) {
			bool boo = *it;
			cout << boo << " ";
		}
		cout << "  ";
		for(vector<bool>::iterator it = MQ.begin(); it!= MQ.end(); ++it) {
			bool boo = *it;
			cout << boo << " ";
		}
		cout << endl;


	}


	//

	cout<<endl;



	vector<bool> container;
	std::copy(MD.begin(), MD.end(), std::back_inserter(container));

	//int cycleCounter ;





}

void convert(int x) {
	vector<bool> ret;
	while(x) {
		if (x&1)
			ret.push_back(1);
		else
			ret.push_back(0);
		x>>=1;
	}
	reverse(ret.begin(),ret.end());
	for(vector<bool>::iterator it = ret.begin(); it!= ret.end(); ++it) {
				bool boo = *it;
				cout << boo << "";
			}

}

void ShiftingZero(vector<bool> &vec1,vector<bool> &vec2) {
	reverse(vec1.begin(),vec1.end());
	vec1.push_back(0);
	reverse(vec1.begin(),vec1.end());

	reverse(vec2.begin(),vec2.end());
	vec2.push_back(vec1[vec1.size()-1]);
	reverse(vec2.begin(),vec2.end());

	vec1.erase(vec1.end() - 1);
	vec2.erase(vec2.end() - 1);

}



