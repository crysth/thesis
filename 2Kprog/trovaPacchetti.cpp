/*--------------------------------------------------------------------



tarantola language `ls`

--------------------------------------------------------------------*/
/*==================================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "libreria.hpp"

using namespace std;

int main(int argc, char **argv) {

//	string path="../outputC/";
//	string language=argv[1];

	Packagegraph *pac;
//	Distribuzioni distr(path,language);
//	Scatterplot scat(path,language);

	for(int i=1; i<argc; i++) {
		pac = new Packagegraph(argv[i]);

	for(size_t k=0; k<pac->N(); k++)

		//if (pac->Nnodes(k)>0 && pac->Nnodes(k)<8000)
		if (pac->Nnodes(k)>1000 ){//&& pac->Nnodes(k,8)<500)
			vector<double> vec=pac->mean_Routdegrees(k);
			if (vec.size()==6 ){
				if (vec[3]>600 )//&& pac->Nnodes(k,8)<500)
				cout<<argv[i]<<"\n";
			}
		}
		delete pac;
	}

	return 0;
}

