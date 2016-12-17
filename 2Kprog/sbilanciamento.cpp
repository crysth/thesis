/*--------------------------------------------------------------------

Sbilanciamento 100 4 `ls`

--------------------------------------------------------------------*/
/*==================================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "libreria.hpp"

using namespace std;

//#define CUTOFF 10
//#define LCUTOFF 4

int main(int argc, char **argv) {

//	string path="../outputC/";
//	string language=argv[1];
//	size_t depth_min=atoi(argv[2]);

	Packagegraph *pac;

	size_t contatore= 0, zeri=0;
	size_t Ncutoff=atoi(argv[1]);
	size_t Lcutoff=atoi(argv[2]);

	for(int i=3; i<argc; i++) {
//		cerr<<argv[i]<<endl;
		pac = new Packagegraph(argv[i]);

		for(size_t k=0; k<pac->N(); k++) {
if(pac->Nnodes(k)<=Ncutoff) continue;
if(pac->depth(k)<=Lcutoff) continue;
			for(size_t j=1; j<pac->depth(k)-1; j++){
				if(j+2 > pac->depth(k)) break;
				if( ( (double)pac->RNnodes(k,j+2)/pac->RNnodes(k,j+1) - (double)pac->RNnodes(k,j+1)/pac->RNnodes(k,j) ) > 0){
					contatore++;
				}
				if( ( (double)pac->RNnodes(k,j+2)/pac->RNnodes(k,j+1) - (double)pac->RNnodes(k,j+1)/pac->RNnodes(k,j) ) == 0){
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
