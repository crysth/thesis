/*--------------------------------------------------------------------

ldeltal `ls`

--------------------------------------------------------------------*/
/*==================================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "libreria.hpp"

#define CPP 3.4865268234 //outdeg
#define JAVA 2.86320647 //outdeg
#define PY 4.2107154419 //outdeg

#define CUTOFF 200

using namespace std;

int main(int argc, char **argv) {

	fstream f;
	size_t help;
	vector<size_t> x,y;

	f.open("../Elephant/Cpp/outputC/distribuzioni/Nnodes.cpp.dat",ios::in);
	f>>help;
	f>>help;
	f>>help;
	while(!f.eof()){
		x.push_back(help);
		f>>help;
		y.push_back(help);
		f>>help;
	}


	TreeMaker alberelli;
	Packagegraph *pac;


	for(size_t j=0; j<x.size(); j++) {
if(x[j]<CUTOFF) continue;
	pac=new Packagegraph;
		for(size_t i=0; i<y[i]; i++) {
			pac->add(alberelli.YuleTree_Nodes(x[j], CPP));
		}
	
		size_t contatore= 0, zeri=0;
		for(size_t k=0; k<pac->N(); k++) {
			for(size_t q=1; q<pac->depth(k)-1; q++){
				if(q+2 > pac->depth(k)) break;
				if( ( (double)pac->RNnodes(k,q+2)/pac->RNnodes(k,q+1) - (double)pac->RNnodes(k,q+1)/pac->RNnodes(k,q) ) > 0){
					contatore++;
				}
				if( ( (double)pac->RNnodes(k,q+2)/pac->RNnodes(k,q+1) - (double)pac->RNnodes(k,q+1)/pac->RNnodes(k,q) ) == 0){
					zeri++;
				}
			}
			if (contatore>0 && (pac->depth(k) - 2 - zeri)>0) cout << pac->Nnodes(k) << "\t" << ((double)contatore / (pac->depth(k) - 2 - zeri) ) << endl;
			if(contatore==0 and pac->depth(k)>2+zeri) cout << pac->Nnodes(k) << "\t" << 0 << endl;
			contatore=0;
			zeri=0;
		}

		delete pac;

	}




	return 0;
}
