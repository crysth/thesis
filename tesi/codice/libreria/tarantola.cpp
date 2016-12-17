/*--------------------------------------------------------------------
tarantola language `ls`
--------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "libreria.hpp"

using namespace std;

int main(int argc, char **argv) {

	string path="../outputC/";
	string language=argv[1];

	Packagegraph *pac;
	Distribuzioni distr(path,language);
	Scatterplot scat(path,language);
	Lineplot line(path,language);

	for(int i=2; i<argc; i++) {
		cout<<argv[i]<<"\n";
		pac = new Packagegraph(argv[i]);

		distr.indegrees(pac);
		distr.roots_outdeg(pac);
		distr.leaves_indeg(pac);
		distr.Nnodes(pac);
		distr.depth(pac);
		distr.leaves_position(pac);
		distr.outdegrees(pac, 5, 1000);

		scat.levels_indegrees(pac);
		scat.levels_outdegrees(pac);
		scat.levels_Nnodes(pac,3);
		scat.levels_outdegmean(pac,4);
		scat.Rlevels_Nnodes(pac,3);
		scat.Rlevels_outdegmean(pac,3, 500);
		scat.LeavesIndegrees_LeavesLevels(pac);
		scat.depth_Nnodes(pac);
		scat.Vnodes_Nnodes(pac);
		scat.leaves_Nnodes(pac,1);
		scat.depth_Nnodes(pac);
		scat.depth_Nnodes_outdeg(pac, 5, 2);
		scat.meanoutdeg_Nnodes_depth(pac);

		line.outdegree(pac,5,1000);
		delete pac;
	}

	return 0;
}


