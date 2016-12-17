/*--------------------------------------------------------------------

//		system("ps aux | grep simulante");

MRmodel farfalla nnodi kappa esse

--------------------------------------------------------------------*/
/*==================================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "libreria.hpp"

using namespace std;

int main(int argc, char **argv) {
	size_t N_STEPS = 4;
	size_t NALBERI = 10;

	string language=argv[1];
	size_t nnodi=atoi(argv[2]);
	size_t kappa=atoi(argv[3]);
	size_t esse=atoi(argv[4]);


	TreeMaker alberelli;
	Packagegraph *scatola;
	scatola=new Packagegraph;

	string path="../STmodel/";

	Distribuzioni distr(path,language);
	Scatterplot scat(path,language);

	cerr<<"ST simulation..."<<endl;
	for(size_t n=1; n<=N_STEPS; n++) {
		cerr<<n<<"\t";
		for(size_t i=0; i<NALBERI; i++) {
			scatola->add(alberelli.MCTree(pow(nnodi,n), kappa, esse));
		}
//		distr.outdegrees(scatola);
//		distr.Nnodes(scatola);
		distr.depth(scatola);
		scat.Rlevels_outdegmean(scatola,1, 1);
//		scat.levels_Nnodes(scatola,2);
//		distr.leaves(scatola);
//		distr.leaves_position(scatola);

//		scat.levels_outdegrees(scatola);
		scat.depth_Nnodes(scatola);
/*		
		scat.levels_outdegmean(scatola,4);*/
		scatola->clear();
	}
	cerr<<endl;
	distr.clear();
	scat.clear();

	delete scatola;

	return 0;
}


