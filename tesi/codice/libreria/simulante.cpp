/*--------------------------------------------------------------------
simulante 7 100
--------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "libreria.hpp"

using namespace std;

#define INDEG_MEAN 1.2012753311
#define OUTDEG_MEAN 1.

int main(int argc, char **argv) {
	size_t N_STEPS = 8;
	size_t NALBERI = 1000;

	TreeMaker alberelli;
	Packagegraph *scatola;
	scatola=new Packagegraph;
	string path, language="sim";
	Distribuzioni distr;
	Scatterplot scat;
	Lineplot liner;
	liner.set_language(language);

	path="../outputC/RussianSim/";
	scatola->set_name("Russian");
	liner.set_path(path);
	distr.set_path(path);
	scat.set_path(path);
	scat.set_language(language);
	liner.set_language(language);
	cerr<<"Russian simulation..."<<endl;

	for(size_t n=1; n<=N_STEPS; n++) {
		cerr<<n<<"\t";
		for(size_t i=0; i<NALBERI; i++) {
			scatola->add(alberelli.RussianTree_Nodes(1, pow(2,n), INDEG_MEAN));
		}
		liner.MeanDepth(scatola);
		distr.outdegrees(scatola);
		scat.levels_indegrees(scatola);
		scat.levels_outdegrees(scatola);
		scat.LeavesIndegrees_LeavesLevels(scatola);
		scat.depth_Nnodes(scatola);
		scat.Vnodes_Nnodes(scatola);
		scat.Rlevels_outdegmean(scatola,3);
		scat.depth_Nnodes(scatola);
		scatola->clear();
	}
	cerr<<endl;
	liner.clear();
	distr.clear();
	scat.clear();

	path="../outputC/RussianSimReversed/";
	scatola->set_name("ReversedRussian");
	liner.set_path(path);
	distr.set_path(path);
	scat.set_path(path);
	scat.set_language(language);
	liner.set_language(language);
	cerr<<"ReversedRussian simulation..."<<endl;

	for(size_t n=1; n<=N_STEPS; n++) {
		cerr<<n<<"\t";
		for(size_t i=0; i<NALBERI; i++) {
			scatola->add(alberelli.ReversedRussianTree_Nodes(1, pow(2,n), OUTDEG_MEAN));
		}
		liner.MeanDepth(scatola);
		distr.outdegrees(scatola);
		scat.levels_indegrees(scatola);
		scat.levels_outdegrees(scatola);
		scat.LeavesIndegrees_LeavesLevels(scatola);
		scat.depth_Nnodes(scatola);
		scat.Vnodes_Nnodes(scatola);
		scatola->clear();
	}
	cerr<<endl;
	liner.clear();
	distr.clear();
	scat.clear();

	path="../outputC/YuleSim/";
	scatola->set_name("Yule");
	liner.set_path(path);
	distr.set_path(path);
	scat.set_path(path);
	scat.set_language(language);
	liner.set_language(language);
	cerr<<"Yule simulation..."<<endl;

	for(size_t n=1; n<=N_STEPS; n++) {
		cerr<<n<<"\t";
		for(size_t i=0; i<NALBERI; i++) {
			scatola->add(alberelli.YuleTree_Nodes(pow(2,n), OUTDEG_MEAN));
		}
		liner.MeanDepth(scatola);
		liner.Rabbit(scatola, 6);
		distr.outdegrees(scatola);
		scat.levels_indegrees(scatola);
		scat.levels_outdegrees(scatola);
		scat.LeavesIndegrees_LeavesLevels(scatola);
		scat.depth_Nnodes(scatola);
		scat.Vnodes_Nnodes(scatola);
		scat.levels_Nnodes(scatola,3,1);
		scat.Rlevels_outdegmean(scatola,3);
		scatola->clear();
	}
	cerr<<endl;
	liner.clear();
	distr.clear();
	scat.clear();

	delete scatola;

	path="../outputC/MCSim/";
	scatola->set_name("mc");
	liner.set_path(path);
	distr.set_path(path);
	scat.set_path(path);
	language="mc";
	scat.set_language(language);
	liner.set_language(language);
	cerr<<"MC simulation..."<<endl;

	for(size_t n=1; n<=N_STEPS; n++) {
		cerr<<n<<"\t";
		for(size_t i=0; i<NALBERI; i++) {
			scatola->add(alberelli.MCTree(pow(2,n), 10000, 200000 ));
		}
		liner.MeanDepth(scatola);
		liner.Rabbit(scatola, 6);
		distr.outdegrees(scatola);
		scat.levels_indegrees(scatola);
		scat.levels_outdegrees(scatola);
		scat.LeavesIndegrees_LeavesLevels(scatola);
		scat.depth_Nnodes(scatola);
		scat.Vnodes_Nnodes(scatola);
		scat.levels_Nnodes(scatola,3,1);
		scat.levels_outdegmean(scatola,3);
		scatola->clear();
	}
	cerr<<endl;
	liner.clear();
	distr.clear();
	scat.clear();

	delete scatola;

	return 0;
}


