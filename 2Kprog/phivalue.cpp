/*--------------------------------------------------------------------

Phivalue cpp 100 4

#define OCPP 0.9663411813 //outdeg
#define OJAVA 0.8586316415 //outdeg
#define OPY 0.9448258812 //outdeg


--------------------------------------------------------------------*/
/*==================================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "libreria.hpp"

/*#define CUTOFF 10

#if CUTOFF == 5
#define CPP (30989./41197.) //phi
#define JAVA (4662./7893.) //phi
#define PY (24203./31124.) //phi
#define OCPP 0.933664
#define OJAVA 0.94092
#define OPY 0.938325
#endif

#if CUTOFF == 10
//#define CPP (16340./22324.) //phi
//#define JAVA (2358./4513.) //phi
//#define PY (14573./18913.) //phi
#define CPP (3578./4777.) //phi
#define JAVA (151./260.) //phi
#define PY (2752./3484.) //phi
#define OCPP 1.1027
#define OJAVA 1.38577
#define OPY 1.06805	
//#define OCPP 0.994234
//#define OJAVA 1.01659
//#define OPY 0.994784
#endif

#if CUTOFF == 50
#define CPP (3184./4607.) //phi
#define JAVA (445./1312.) //phi
#define PY (2918./4058.) //phi
#define OCPP 1.07879
#define OJAVA 1.13159
#define OPY 1.06287
#endif

#if CUTOFF == 100
#define CPP (1623./2266.) //phi
#define JAVA (227./847.) //phi
#define PY (1454./2110.) //phi
#define OCPP 1.10404
#define OJAVA 1.17613
#define OPY 1.09006
#endif

//#define OCPP 1.11142 //outdeg come media di medie da 10 in poi
//#define OCPP 3.4865268234 //outdeg
//#define OJAVA 2.86320647 //outdeg
//#define OPY 4.2107154419 //outdeg*/

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

//	system(("awk '$1>"+Ncut+" && $2>"+Lcut+"' "+path+"outputC/scatterplot/NnodesVSdepthVSoutdeg."+inp+".dat | awk '{sum+=$3}END{print sum/NR}' > "+foutdeg).c_str());
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
//cout<<j<<"\t";
//		if(x[j]<=Ncut) continue;
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
//cout<<endl<<endl;
	double value=double(phi)/(phi+no);
	if(value >= soglia) cout<<1<<"\t"<<value<<"\t"<<phi<<"/"<<(phi+no)<<"\t"<<soglia<<"\t"<<a<<"/"<<b<<"\t"<<test<<endl;
	else cout<<0<<"\t"<<value<<"\t"<<phi<<"/"<<(phi+no)<<"\t"<<soglia<<"\t"<<a<<"/"<<b<<"\t"<<test<<endl;
}
	system(("rm "+sbilancia+" "+ftest+" "+foutdeg+" "+fnodi).c_str());

	return 0;
}
