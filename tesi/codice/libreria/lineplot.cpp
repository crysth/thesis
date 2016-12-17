#include "lineplot.hpp"

/*--------------------------------------------------------------------
 Costruttore
--------------------------------------------------------------------*/
Lineplot::Lineplot(): check(0), mean_check(0), _path(""), _language("") {};
Lineplot::Lineplot(string path): check(1), mean_check(0), _path(path), _language("") {};
Lineplot::Lineplot(string path, string language): check(1), mean_check(0), _path(path), _language(language) {};
/*--------------------------------------------------------------------
 Distruttore
--------------------------------------------------------------------*/
Lineplot::~Lineplot(){
	_f1.close(); _f2.close(); _f3.close(); _f4.close(); _f5.close();
};
/*--------------------------------------------------------------------
 Functions
--------------------------------------------------------------------*/
void Lineplot::clear(){
	_f1.close(); _f2.close(); _f3.close(); _f4.close(); _f5.close();
	check=0;
	mean_check=0;
	_path="";
	_language="";
};
/*------------------------------------------------------------------*/
void Lineplot::set_path(){
	check=1;
	system("mkdir -p ../outputC");
	_path="../outputC/";
};
void Lineplot::set_path(string path){
	check=1;
	system(("mkdir -p "+path).c_str());
	_path=path;
};
void Lineplot::set_language(string language){
	_language=language;
};
/*------------------------------------------------------------------*/
void Lineplot::Rabbit(Packagegraph *pac, size_t limit){
	if (check==0) cerr<<"Lineplot:: path non dichiarato!"<<endl;
	else {
		system(("mkdir -p "+_path+"/rabbit/").c_str());
		string dot=".rate";
		for(size_t k=0; k<pac->N(); k++) {
			if(pac->depth(k)> limit) {
				_f1.open(_path+"/rabbit/"+_language+"."+pac->name()+"."+to_string(k)+dot,ios::out);
				_f1<<"#Level"<<"\t"<<"n(j)/n(j+1)\tNnodes\n";
				for(size_t j=1; j<pac->depth(k); j++){
					_f1 << j << "\t" << (double)pac->RNnodes(k,j)/pac->RNnodes(k,j+1) << "\t" << pac->Nnodes(k) << endl;
				}
				_f1.close();
			}
		}
	}
};
/*------------------------------------------------------------------*/
void Lineplot::Pricer(Packagegraph *pac, size_t limit){
	if (check==0) cerr<<"Lineplot:: path non dichiarato!"<<endl;
	else {
		system(("mkdir -p "+_path+"/prices/recursive/").c_str());
		string dot=".price";
	
		for(size_t i=0; i<pac->N(); i++) {
			if(pac->depth(i)> limit) {
				_f1.open(_path+"/prices/"+_language+"."+pac->name()+"."+to_string(i)+dot,ios::out);
				_f1<<"#lambda\tcosto\n";
				_f2.open(_path+"/prices/recursive/"+_language+".R."+pac->name()+"."+to_string(i)+dot,ios::out);
				_f2<<"#lambda\tcosto_ricorsivo\n";
				for(double lambda=0.0; lambda <= 1.0; lambda += 0.025) {
					_f1 << lambda << "\t" << pac->cost(i, lambda) << "\t" << pac->Nnodes(i) << endl;
					_f2 << lambda << "\t" << pac->recursive_cost(i, lambda) << pac->Nnodes(i) << endl;
				}
				_f1.close();
				_f2.close();
			}
		}
	}
};
/*------------------------------------------------------------------*/
void Lineplot::MeanDepth(Packagegraph *pac){
	if (check==0) cerr<<"Lineplot:: path non dichiarato!"<<endl;
	else {
		if (mean_check==0) {
			system(("mkdir -p "+_path+"/scatterplot/").c_str());
			string dot=".dat";
			_f3.open(_path+"/scatterplot/"+_language+".DepthVSNnodes."+pac->name()+dot,ios::out);
			_f3<<"#Numero_nodi\tmean_depth\n";
			mean_check=1;
		}
		_f3 << pac->Nnodes(0) << "\t" << pac->mean_depth() << endl;
	}
};
/*------------------------------------------------------------------*/
void Lineplot::outdegree(Packagegraph *pac, size_t cut_lev, size_t cut_nodes){
	if (check==0) cerr<<"Lineplot:: path non dichiarato!"<<endl;
	else {
		system(("mkdir -p "+_path+"/outdegrees/").c_str());
		string dot=".outd";
		for(size_t k=0; k<pac->N(); k++) {
			if(pac->depth(k)< cut_lev) continue; 
			if(pac->Nnodes(k)< cut_nodes) continue; 
			_f4.open(_path+"/outdegrees/U"+to_string(pac->Nnodes(k))+"."+to_string(pac->depth(k))+"."+pac->name()+"."+to_string(k)+_language+dot,ios::out);
			for(size_t j=0; j<pac->Nnodes(k); j++){
				_f4 << pac->outdeg(k,j)<< endl;
			}
			_f4.close();
			system(("cd "+_path+"/outdegrees/; Uniqa;").c_str());
		}
	}
};
/*------------------------------------------------------------------*/
void Lineplot::indegree(Packagegraph *pac, size_t cut_lev, size_t cut_nodes){
	if (check==0) cerr<<"Lineplot:: path non dichiarato!"<<endl;
	else {
		system(("mkdir -p "+_path+"/indegrees/").c_str());
		string dot=".ind";
		for(size_t k=0; k<pac->N(); k++) {
			if(pac->depth(k)< cut_lev) continue; 
			if(pac->Nnodes(k)< cut_nodes) continue; 
			_f5.open(_path+"/indegrees/U"+to_string(pac->Nnodes(k))+"."+to_string(pac->depth(k))+"."+pac->name()+"."+to_string(k)+_language+dot,ios::out);
			for(size_t j=0; j<pac->Nnodes(k); j++){
				_f5 << pac->indeg(k,j)<< endl;
			}
			_f5.close();
			system(("cd "+_path+"/indegrees/; Uniqa;").c_str());
		}
	}
};
/*------------------------------------------------------------------*/
