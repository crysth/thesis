/*--------------------------------------------------------------------
trovaPacchetti `ls`
--------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "libreria.hpp"

using namespace std;

int main(int argc, char **argv) {

	Packagegraph *pac;

	for(int i=1; i<argc; i++) {
		pac = new Packagegraph(argv[i]);

	for(size_t k=0; k<pac->N(); k++)
		if (pac->Nnodes(k)>1000 ){
			vector<double> vec=pac->mean_Routdegrees(k);
			if (vec.size()==6 ){
				if (vec[3]>600 )
				cout<<argv[i]<<"\n";
			}
		}
		delete pac;
	}

	return 0;
}

