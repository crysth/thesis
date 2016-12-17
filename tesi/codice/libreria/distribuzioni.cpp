#include "distribuzioni.hpp"
/*--------------------------------------------------------------------
 Costruttore
--------------------------------------------------------------------*/
Distribuzioni::Distribuzioni(): check(0), _check1(0), _check2(0), _check3(0), _check4(0), _check5(0), _check6(0), _check7(0), _check8(0), _check11(0) {};
Distribuzioni::Distribuzioni(string path): check(1), _check1(0), _check2(0), _check3(0), _check4(0), _check5(0), _check6(0), _check7(0), _check8(0), _check11(0), _path(path) {
	system(("mkdir -p "+path+"/distribuzioni/").c_str());
};
Distribuzioni::Distribuzioni(string path, string language): check(1), _check1(0), _check2(0), _check3(0), _check4(0), _check5(0), _check6(0), _check7(0), _check8(0), _check11(0), _path(path), _language(language) {
	system(("mkdir -p "+path+"/distribuzioni/").c_str());
};
/*--------------------------------------------------------------------
 Distruttore
--------------------------------------------------------------------*/
Distribuzioni::~Distribuzioni(){
	_f1.close(); _f2.close(); _f3.close(); _f4.close(); _f5.close(); _f6.close(); _f7.close(); _f8.close(); _f11.close();
	if(check==1) system(("cd "+_path+"/distribuzioni/; Uniqa;").c_str());
};
/*--------------------------------------------------------------------
 Functions
--------------------------------------------------------------------*/
void Distribuzioni::set_path(){
	check=1;
	_path="../outputC/";
	system("mkdir -p ../outputC/distribuzioni/");
};
void Distribuzioni::set_path(string path){
	check=1;
	_path=path;
	system(("mkdir -p "+path+"/distribuzioni/").c_str());
};
/*------------------------------------------------------------------*/
void Distribuzioni::outdegrees(Packagegraph *pac){
	if (check==0) cerr<<"Distribuzioni:: path non dichiarato!"<<endl;
	else {
		if(_check1==0){
			_f1.open(_path+"/distribuzioni/Uoutdegrees."+_language+".dat",ios::out);
			_check1=1;
		}
		vector<size_t> _outdeg=pac->outdegrees();
		for(size_t i=0; i<_outdeg.size(); i++) {
			_f1<<_outdeg[i]<<"\n";
		}
	}
};
/*------------------------------------------------------------------*/
void Distribuzioni::outdegrees(Packagegraph *pac, size_t cut_lev, size_t cut_nodes){
	if (check==0) cerr<<"Distribuzioni:: path non dichiarato!"<<endl;
	else {
		if(_check11==0){
			_f11.open(_path+"/distribuzioni/UoutdegreesCUT."+_language+".dat",ios::out);
			_check11=1;
		}
		for(size_t i=0; i<pac->N(); i++) {
			if(pac->depth(i)<cut_lev) continue;
			if(pac->Nnodes(i)<cut_nodes) continue;
			vector<size_t> _outdeg=pac->outdegrees(i);
			for(size_t i=0; i<_outdeg.size(); i++) {
				_f11<<_outdeg[i]<<"\n";
			}
		}
	}
};
/*------------------------------------------------------------------*/
void Distribuzioni::indegrees(Packagegraph *pac){
	if (check==0) cerr<<"Distribuzioni:: path non dichiarato!"<<endl;
	else {
		if(_check2==0){
			_f2.open(_path+"/distribuzioni/Uindegrees."+_language+".dat",ios::out);
			_check2=1;
		}
		vector<size_t> _indeg=pac->indegrees();
		for(size_t i=0; i<_indeg.size(); i++) {
			_f2<<_indeg[i]<<"\n";
		}
	}
};
/*------------------------------------------------------------------*/
void Distribuzioni::roots_outdeg(Packagegraph *pac){
	if (check==0) cerr<<"Distribuzioni:: path non dichiarato!"<<endl;
	else {
		if(_check3==0){
			_f3.open(_path+"/distribuzioni/Uoutdeg_roots."+_language+".dat",ios::out);
			_check3=1;
		}
		vector<size_t> _roots_outdeg=pac->roots_outdegrees();
		for(size_t i=0; i<_roots_outdeg.size(); i++) {
			_f3<<_roots_outdeg[i]<<"\n";
		}
	}
};
/*------------------------------------------------------------------*/
void Distribuzioni::leaves_indeg(Packagegraph *pac){
	if (check==0) cerr<<"Distribuzioni:: path non dichiarato!"<<endl;
	else {
		if(_check4==0){
			_f4.open(_path+"/distribuzioni/Uindeg_leaves."+_language+".dat",ios::out);
			_check4=1;
		}
		vector<size_t> _leaves_indeg=pac->leaves_indegrees();
		for(size_t i=0; i<_leaves_indeg.size(); i++) {
			_f4<<_leaves_indeg[i]<<"\n";
		}
	}
};
/*------------------------------------------------------------------*/
void Distribuzioni::Nnodes(Packagegraph *pac){
	if (check==0) cerr<<"Distribuzioni:: path non dichiarato!"<<endl;
	else {
		if(_check5==0){
			_f5.open(_path+"/distribuzioni/UNnodes."+_language+".dat",ios::out);
			_check5=1;
		}
		size_t Ngrafi=pac->N();
		for(size_t i=0; i<Ngrafi; i++) {
			_f5<<pac->Nnodes(i)<<"\n";
		}
	}
};
/*------------------------------------------------------------------*/
void Distribuzioni::depth(Packagegraph *pac){
	if (check==0) cerr<<"Distribuzioni:: path non dichiarato!"<<endl;
	else {
		if(_check6==0){
			_f6.open(_path+"/distribuzioni/Udepth."+_language+".dat",ios::out);
			_check6=1;
		}
		size_t Ngrafi=pac->N();
		for(size_t i=0; i<Ngrafi; i++) {
			_f6<<pac->depth(i)<<"\n";
		}
	}
};
/*------------------------------------------------------------------*/
void Distribuzioni::leaves_position(Packagegraph *pac){
	if (check==0) cerr<<"Distribuzioni:: path non dichiarato!"<<endl;
	else {
		if(_check7==0){
			_f7.open(_path+"/distribuzioni/Leavesposition."+_language+".dat",ios::out);
			_check7=1;
		}
		size_t Ngrafi=pac->N();
		for(size_t i=0; i<Ngrafi; i++) {
			size_t Nlevels=pac->depth(i);
			vector<size_t> _leaves_depth=pac->leaves_depth(i);
			size_t dpt=_leaves_depth.size();
			for(size_t j=0;j<dpt;j++){
				_f7<<double(_leaves_depth[j])/ Nlevels <<"\t"<<1./dpt<< "\n";
			}
		}
	}
};
/*------------------------------------------------------------------*/
void Distribuzioni::leaves(Packagegraph *pac){
	if (check==0) cerr<<"Distribuzioni:: path non dichiarato!"<<endl;
	else {
		if(_check8==0){
			_f8.open(_path+"/distribuzioni/Uleaves."+_language+".dat",ios::out);
			_check8=1;
		}
		size_t Ngrafi=pac->N();
		for(size_t i=0; i<Ngrafi; i++) {
			_f8<< pac->Nleaves(i) << "\n";
		}
	}
};
/*------------------------------------------------------------------*/
void Distribuzioni::clear(){
	_f1.close(); _f2.close(); _f3.close(); _f4.close(); _f5.close(); _f6.close(); _f7.close(); _f8.close(); _f11.close();
	if(check==1) system(("cd "+_path+"/distribuzioni/; Uniqa;").c_str());
	check=0;
	_check1=0;
	_check2=0;
	_check3=0;
	_check4=0;
	_check5=0;
	_check6=0;
	_check7=0;
	_check8=0;
	_check11=0;
};
/*------------------------------------------------------------------*/
