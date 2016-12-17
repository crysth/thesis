/*--------------------------------------------------------------------
MRvalue cpp 
--------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "libreria.hpp"

using namespace std;

int main(int argc, char **argv) {
	string inp=argv[1];

	string Ncut="50";
	string Lcut="4";

	string sNseq="1000";
	string sNsym="20000";

	size_t Nvolte=1;
	string path="../MRval/";

	fstream f;
	size_t help;
	vector<size_t> x,y;
	string fpath="/home/cry/Elephant/";
	if(inp=="cpp") fpath+="Cpp/";
	if(inp=="java") fpath+="Java/";
	if(inp=="py") fpath+="Python/";

	string fnodi="/home/cry/2Kprog/.nodi."+inp+Ncut+"_"+Lcut+".dat";

	//ottengo l'elenco della popolazione delle taglie dei nodi dati i cutoff
	system(("awk '$2>"+Lcut+" && $1>"+Ncut+"' "+fpath+"outputC/scatterplot/SdepVSNnodes."+inp+".dat | awk '{print $1}' | sort -n | uniq -c | awk '{print $2,$1}' | sort -n > "+fnodi).c_str());	
	f.open(fnodi.c_str(),ios::in);

	f>>help;
	while(!f.eof()){
		x.push_back(help);
		f>>help;
		y.push_back(help);
		f>>help;
	}

	size_t Nseq=atoi(sNseq.c_str());
	size_t Nsym=atoi(sNsym.c_str());
	size_t iLcut=atoi(Lcut.c_str());

	string language=sNseq+"_"+sNsym+inp;

	TreeMaker alberelli;
	Packagegraph *scatola;
	Distribuzioni distr(path,language);
	Scatterplot scat(path,language);

for(size_t w=0; w<Nvolte; w++) {
	for(size_t j=0; j<x.size(); j++) {
		scatola=new Packagegraph;
		for(size_t i=0; i<y[j]; i++) {
			scatola->add(alberelli.MCTree(x[j], Nseq, Nsym));
		}
		distr.outdegrees(scatola);
		distr.Nnodes(scatola);
		distr.depth(scatola);

		scat.levels_outdegrees(scatola);
		scat.depth_Nnodes(scatola);
		scat.levels_Nnodes(scatola,iLcut);
		scat.Rlevels_Nnodes(scatola,iLcut);
		scat.levels_outdegmean(scatola,iLcut);

		delete scatola;
	}
}
	system(("rm "+fnodi).c_str());

	return 0;
}
