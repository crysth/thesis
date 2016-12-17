/*--------------------------------------------------------------------
Phivalue cpp Nnodes_cutoff level_cutoff Nsim
--------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "libreria.hpp"

using namespace std;

int main(int argc, char **argv) {

	fstream f;
	size_t help;
	vector<size_t> x,y;
	double figli, soglia;
	string scest;
	string inp=argv[1];
	string Ncut=argv[2];
	string Lcut=argv[3];
	size_t Nvolte=atoi(argv[4]);
	string path="/home/cry/Elephant/";

	if(inp=="cpp") path+="Cpp/";
	if(inp=="java") path+="Java/";
	if(inp=="py") path+="Python/";

	string sbilancia="/home/cry/2Kprog/.sbilancia."+inp+Ncut+"_"+Lcut+".dat";
	string ftest="/home/cry/2Kprog/.test."+inp+Ncut+"_"+Lcut+".dat";
	string foutdeg="/home/cry/2Kprog/.outdeg."+inp+Ncut+"_"+Lcut+".dat";
	string fnodi="/home/cry/2Kprog/.nodi."+inp+Ncut+"_"+Lcut+".dat";

	system(("cd "+path+"Numerelli/; Sbilanciamento "+Ncut+" "+Lcut+" `ls` > "+sbilancia+"; Test "+sbilancia+" > "+ftest).c_str());
	f.open(ftest.c_str(),ios::in);
	f>>scest;
	size_t a,b;
	double test;
	f>>a;
	f>>scest;
	f>>b;
	f>>test;
	f.close();
	soglia=(double) a/b;

	system(("awk '$1>"+Ncut+" && $2>"+Lcut+"' "+path+"outputC/scatterplot/SoutdegVSNnodesVSdepth."+inp+".dat | awk '{sum+=$3}END{print sum/NR}' > "+foutdeg).c_str());
	f.open(foutdeg.c_str(),ios::in);
	f>>figli;
	f.close();

	system(("awk '$2>"+Lcut+" && $1>"+Ncut+"' "+path+"outputC/scatterplot/SdepVSNnodes."+inp+".dat | awk '{print $1}' | sort -n | uniq -c | awk '{print $2,$1}' | sort -n > "+fnodi).c_str());	
	f.open(fnodi.c_str(),ios::in);

	f>>help;
	while(!f.eof()){
		x.push_back(help);
		f>>help;
		y.push_back(help);
		f>>help;
	}


	TreeMaker alberelli;
	Packagegraph *pac;

	for(size_t w=0; w<Nvolte; w++) {
		size_t phi=0, no=0;

		for(size_t j=0; j<x.size(); j++) {
			pac=new Packagegraph;
			for(size_t i=0; i<y[j]; i++) {
				pac->add(alberelli.YuleTree_Nodes(x[j], figli));
			}
			size_t contatore= 0, zeri=0;
			for(size_t k=0; k<pac->N(); k++) {
				for(size_t q=1; q<pac->depth(k)-1; q++){
					if(q+2 > pac->depth(k)) break;
					if(( (double)pac->RNnodes(k,q+2)/pac->RNnodes(k,q+1) - (double)pac->RNnodes(k,q+1)/pac->RNnodes(k,q) ) > 0){
						contatore++;
					}
					if(((double)pac->RNnodes(k,q+2)/pac->RNnodes(k,q+1) - (double)pac->RNnodes(k,q+1)/pac->RNnodes(k,q) ) == 0){
						zeri++;
					}
				}
				if (contatore>0 && (pac->depth(k) - 2 - zeri)>0) {
					if((double)contatore / (pac->depth(k) - 2 - zeri) > 0.5) phi++;
					else no++;
				}
				if(contatore==0 and pac->depth(k)>2+zeri) no++;
				contatore=0;
				zeri=0;
			}
			delete pac;
		}

		double value=double(phi)/(phi+no);
		if(value >= soglia) cout<<1<<"\t"<<value<<"\t"<<phi<<"/"<<(phi+no)<<"\t"<<soglia<<"\t"<<a<<"/"<<b<<"\t"<<test<<endl;
		else cout<<0<<"\t"<<value<<"\t"<<phi<<"/"<<(phi+no)<<"\t"<<soglia<<"\t"<<a<<"/"<<b<<"\t"<<test<<endl;
	}
	system(("rm "+sbilancia+" "+ftest+" "+foutdeg+" "+fnodi).c_str());

	return 0;
}
