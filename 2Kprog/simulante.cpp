/*--------------------------------------------------------------------

//		system("ps aux | grep simulante");

simulante 7 100

--------------------------------------------------------------------*/
/*==================================================================*/

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

/*	if(argc==2) {
		N_STEPS = atoi(argv[1]);
	}
	if(argc==3) {
		N_STEPS = atoi(argv[1]);
		NALBERI = atoi(argv[2]);
	}
	else if (argc > 3) {
		cerr<<"Too many arguments!"<<endl;
		return -1;
	}
*/

	TreeMaker alberelli;
	Packagegraph *scatola;
	scatola=new Packagegraph;
	string path, language="sim";
	Distribuzioni distr;
	Scatterplot scat;
	Lineplot liner;
	liner.set_language(language);

///*
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
//		liner.MeanDepth(scatola);
//		distr.add(scatola);
//		scat.levels_indegrees(scatola);
//		scat.levels_outdegrees(scatola);
//		scat.LeavesIndegrees_LeavesLevels(scatola);
//		scat.depth_Nnodes(scatola);
//		scat.Vnodes_Nnodes(scatola);
//scat.Rlevels_outdegmean(scatola,3);
		scat.depth_Nnodes(scatola);
		scatola->clear();
	}
	cerr<<endl;
	liner.clear();
	distr.clear();
	scat.clear();//*/

/*
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
//		distr.add(scatola);
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
	scat.clear();//*/

/*
	path="../outputC/YuleSim/";
	scatola->set_name("Yule");
	liner.set_path(path);
	distr.set_path(path);
	scat.set_path(path);
	scat.set_language(language);
	liner.set_language(language);
	cerr<<"Yule simulation..."<<endl;
//N_STEPS=1;

	for(size_t n=1; n<=N_STEPS; n++) {
		cerr<<n<<"\t";
		for(size_t i=0; i<NALBERI; i++) {
			scatola->add(alberelli.YuleTree_Nodes(pow(2,n), OUTDEG_MEAN));
		}
//		liner.MeanDepth(scatola);
//		liner.Rabbit(scatola, 6);
//		distr.add(scatola);
//		scat.levels_indegrees(scatola);
//		scat.levels_outdegrees(scatola);
//		scat.LeavesIndegrees_LeavesLevels(scatola);
		scat.depth_Nnodes(scatola);
//		scat.Vnodes_Nnodes(scatola);
//scat.levels_Nnodes(scatola,3,1);
//scat.Rlevels_outdegmean(scatola,3);
		scatola->clear();
	}
	cerr<<endl;
	liner.clear();
	distr.clear();
	scat.clear();

	delete scatola;//*/

/*
	path="../outputC/MCSim/";
	scatola->set_name("mc");
	liner.set_path(path);
	distr.set_path(path);
	scat.set_path(path);
	language="mc";
	scat.set_language(language);
	liner.set_language(language);
	cerr<<"MC simulation..."<<endl;
NALBERI = 1;
N_STEPS=8;
	for(size_t n=1; n<=N_STEPS; n++) {
		cerr<<n<<"\t";
/*		for(size_t i=0; i<NALBERI; i++) {
			scatola->add(alberelli.MCTree(1000*n/*pow(2,n)*//*, 10000, 200000 ));*/
//			scatola->add(alberelli.MCTree(n*100, 60, 600 ));
//		}
//		liner.MeanDepth(scatola);
//		liner.Rabbit(scatola, 6);
//		distr.add(scatola);
//		distr.outdegrees(scatola);
//		scat.levels_indegrees(scatola);
//		scat.levels_outdegrees(scatola);
//		scat.LeavesIndegrees_LeavesLevels(scatola);
//		scat.depth_Nnodes(scatola);
//		scat.Vnodes_Nnodes(scatola);
//scat.levels_Nnodes(scatola,3,1);
/*scat.levels_outdegmean(scatola,3);
		scatola->clear();
	}
	cerr<<endl;
	liner.clear();
	distr.clear();
	scat.clear();

	delete scatola;//*/
/* indegree medio degli alberi prodotti */
/*	for(size_t n=1; n<=N; n++) {
		vector<size_t> indegrees;
		for(size_t i=0; i<NALBERI; i++)
			scatola.add(alberelli.YuleTree(1, pow(2,n), INDEG_MEAN));
		indegrees = scatola.outdegrees();
		vector<size_t> leaves = scatola.leaves_indegrees();
		double mean = 0;
		for(size_t i=0; i<indegrees.size(); i++) mean += indegrees[i];
		cout << mean/(indegrees.size()-leaves.size()) << endl;
		scatola.clear();
	}
//*/ 

	return 0;
}


