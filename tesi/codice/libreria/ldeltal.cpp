/*--------------------------------------------------------------------

ldeltal language `ls`

--------------------------------------------------------------------*/
/*==================================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "libreria.hpp"

using namespace std;

int main(int argc, char **argv) {

	string language=argv[1];
	Packagegraph *pac;

	double data[1000];
	size_t contatore[1000];

	for(size_t i=0; i<1000; i++) {
		data[i] = 0.0;
		contatore[i] = 0;
	}

	for(int i=2; i<argc; i++) {
		pac = new Packagegraph(argv[i]);
		for(size_t k=0; k<pac->N(); k++) {
			for(size_t j=1; j<pac->depth(k)-1; j++){
				if(j+2 >= pac->depth(k)-1) break;
				data[j] += (double)pac->RNnodes(k,j)/pac->RNnodes(k,j+1) - (double)pac->RNnodes(k,j+1)/pac->RNnodes(k,j+2);
				contatore[j]++;
			}
		}
		delete pac;
	}

	for(size_t i=1; i<100; i++) {
		if (contatore[i]>0 ) cout << i << "\t" << data[i]/contatore[i] << endl;
	}

	return 0;
}
