#include "scatterplot.hpp"

/*--------------------------------------------------------------------
 Costruttore
--------------------------------------------------------------------*/
Scatterplot::Scatterplot(): _check(0), _check1(0), _check2(0), _check3(0), _check4(0), _check5(0), _check6(0), _check7(0), _check8(0), _check9(0), _check10(0) {};
Scatterplot::Scatterplot(string path): _check(1), _check1(0), _check2(0), _check3(0), _check4(0), _check5(0), _check6(0), _check7(0), _check8(0), _check9(0), _check10(0), _path(path) {
	system(("mkdir -p "+path+"/scatterplot/").c_str());
};
Scatterplot::Scatterplot(string path, string language): _check(1), _check1(0), _check2(0), _check3(0), _check4(0), _check5(0), _check6(0), _check7(0), _check8(0), _check9(0), _check10(0), _path(path), _language(language) {
	system(("mkdir -p "+path+"/scatterplot/").c_str());
};
/*--------------------------------------------------------------------
 Distruttore
--------------------------------------------------------------------*/
Scatterplot::~Scatterplot(){
	_f1.close(); _f2.close(); _f3.close(); _f4.close(); _f5.close(); _f6.close(); _f7.close(); _f8.close(); _f9.close(); _f10.close();
	_ff1.close(); _ff2.close(); _ff3.close(); _ff4.close(); _ff5.close(); _ff6.close(); _ff7.close(); //_f8.close(); _f9.close();
	if(_check==1) system(("cd "+_path+"/scatterplot/; Sorta;").c_str());
};
/*--------------------------------------------------------------------
 Functions
--------------------------------------------------------------------*/
void Scatterplot::set_path(){
	_check=1;
	_path="../outputC/";
	set_path(_path);
	system(("mkdir -p "+_path+"/scatterplot/").c_str());
};
void Scatterplot::set_path(string path){
	_check=1;
	_path=path;
	system(("mkdir -p "+path+"/scatterplot/").c_str());
};
void Scatterplot::set_language(string language){
	_language = language;
}
/*------------------------------------------------------------------*/
void Scatterplot::leaves_Nnodes(Packagegraph *pac, size_t minimum){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check10==0){
			_f10.open(_path+"/scatterplot/SleavesVSNnodes."+_language+".dat",ios::out);
			_f10<<"#leaves\tNnodes\n";
			_check10=1;
		}
		for(size_t j=0;j<pac->N();j++){
			if(pac->Nnodes(j) > minimum) _f10<<(pac->Nleaves(j))<<"\t"<<pac->Nnodes(j)<<"\n";
		}
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::levels_Nnodes(Packagegraph *pac, size_t minimum){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check1==0){
			_f1.open(_path+"/scatterplot/SlevelVSNnodes."+_language+".dat",ios::out);
			_f1<<"#levels\tNnodes\n";
			_check1=1;
		}
		for(size_t j=0;j<pac->N();j++){
			vector<size_t> brothers = pac->brothers(j);
			if(brothers.size()>minimum){
				for(size_t i=0; i<brothers.size(); i++) {
					_f1<<i+1<<"\t"<<brothers[i]<<"\t"<<pac->Nnodes(j)<<"\n";
				}
			}
		}
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::Rlevels_outdegmean(Packagegraph *pac, size_t minimum, size_t nodimin){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check8==0){
			_f8.open(_path+"/scatterplot/RlevelVSoutdegmean."+_language+".dat",ios::out);
			_f8<<"#Rlevels\toutdegmean\n";
			_check8=1;
		}
		for(size_t j=0;j<pac->N();j++){
			if( pac->Nnodes(j) < nodimin) continue;
			vector<double> outdeg = pac->mean_Routdegrees(j);
			
			if(outdeg.size()>minimum){
				for(size_t i=0; i<outdeg.size(); i++) {
					_f8<<i+1<<"\t"<<outdeg[i]<<"\t"<<pac->Nnodes(j)<<"\n";
				}
			}
		}
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::levels_outdegmean(Packagegraph *pac, size_t minimum){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check9==0){
			_f9.open(_path+"/scatterplot/levelVSoutdegmean."+_language+".dat",ios::out);
			_f9<<"#levels\toutdegmean\n";
			_check9=1;
		}
		for(size_t j=0;j<pac->N();j++){
			vector<double> outdeg = pac->mean_outdegrees(j);
			
			if(outdeg.size()>minimum){
				for(size_t i=0; i<outdeg.size(); i++) {
					_f9<<i+1<<"\t"<<outdeg[i]<<"\t"<<pac->Nnodes(j)<<"\n";
				}
			}
		}
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::levels_Nnodes(Packagegraph *pac, size_t minimum, bool level){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {
	  if(_check1==0){
	    _ff1.open(_path+"/scatterplot/1lVSN."+_language+".dat",ios::out);
	    _ff2.open(_path+"/scatterplot/2lVSN."+_language+".dat",ios::out);
	    _ff3.open(_path+"/scatterplot/3lVSN."+_language+".dat",ios::out);
	    _ff4.open(_path+"/scatterplot/4lVSN."+_language+".dat",ios::out);
	    _ff5.open(_path+"/scatterplot/5lVSN."+_language+".dat",ios::out);
	    _ff6.open(_path+"/scatterplot/6lVSN."+_language+".dat",ios::out);
	    _ff7.open(_path+"/scatterplot/7lVSN."+_language+".dat",ios::out);
	    _ff1<<"#levels\tNnodes\n";
	    _ff2<<"#levels\tNnodes\n";
	    _ff3<<"#levels\tNnodes\n";
	    _ff4<<"#levels\tNnodes\n";
	    _ff5<<"#levels\tNnodes\n";
	    _ff6<<"#levels\tNnodes\n";
	    _ff7<<"#levels\tNnodes\n";
	    _check1=1;
	  }
	  for(size_t j=0;j<pac->N();j++){
	  	vector<size_t> brothers = pac->brothers(j);
	  	if(brothers.size()>=minimum){
	  	  if(brothers.size()==minimum){
	  	    for(size_t i=0; i<brothers.size(); i++) {
	  	      _ff1<<double(i+1)/brothers.size()<<"\t"<<double(brothers[i])/pac->Nnodes(j)<<"\t"<<pac->Nnodes(j)<<"\n";
	  	    }
	  	  }
	  	  if(brothers.size()==minimum+1){
	  	    for(size_t i=0; i<brothers.size(); i++) {
	  	      _ff2<<double(i+1)/brothers.size()<<"\t"<<double(brothers[i])/pac->Nnodes(j)<<"\t"<<pac->Nnodes(j)<<"\n";
	  	    }
	  	  }
	  	  if(brothers.size()==minimum+2){
	  	    for(size_t i=0; i<brothers.size(); i++) {
	  	      _ff3<<double(i+1)/brothers.size()<<"\t"<<double(brothers[i])/pac->Nnodes(j)<<"\t"<<pac->Nnodes(j)<<"\n";
	  	    }
	  	  }
	  	  if(brothers.size()==minimum+3){
	  	    for(size_t i=0; i<brothers.size(); i++) {
	  	      _ff4<<double(i+1)/brothers.size()<<"\t"<<double(brothers[i])/pac->Nnodes(j)<<"\t"<<pac->Nnodes(j)<<"\n";
	  	    }
	  	  }
	  	  if(brothers.size()==minimum+4){
	  	    for(size_t i=0; i<brothers.size(); i++) {
	  	      _ff5<<double(i+1)/brothers.size()<<"\t"<<double(brothers[i])/pac->Nnodes(j)<<"\t"<<pac->Nnodes(j)<<"\n";
	  	    }
	  	  }
	  	  if(brothers.size()==minimum+5){
	  	    for(size_t i=0; i<brothers.size(); i++) {
	  	      _ff6<<double(i+1)/brothers.size()<<"\t"<<double(brothers[i])/pac->Nnodes(j)<<"\t"<<pac->Nnodes(j)<<"\n";
	  	    }
	  	  }
	  	  if(brothers.size()==minimum+6){
	  	    for(size_t i=0; i<brothers.size(); i++) {
	  	      _ff7<<double(i+1)/brothers.size()<<"\t"<<double(brothers[i])/pac->Nnodes(j)<<"\t"<<pac->Nnodes(j)<<"\n";
	  	    }
	  	  }
	  	}
	  }
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::Rlevels_Nnodes(Packagegraph *pac, size_t minimum){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check1==0){
			_f1.open(_path+"/scatterplot/SRlevelVSNnodes."+_language+".dat",ios::out);
			_f1<<"#Rlevels\tNnodes\n";
			_check1=1;
		}
		for(size_t j=0;j<pac->N();j++){
			vector<size_t> Rbrothers = pac->Rbrothers(j);
			if(Rbrothers.size()>minimum){
				for(size_t i=0; i<Rbrothers.size(); i++) {
					_f1<<i+1<<"\t"<<Rbrothers[i]<<"\t"<<pac->Nnodes(j)<<"\n";
				}
			}
		}
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::levels_indegrees(Packagegraph *pac){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check1==0){
			_f1.open(_path+"/scatterplot/SlevelVSindeg."+_language+".dat",ios::out);
			_f1<<"#indegrees\tlevels\n";
			_check1=1;
		}
		_indeg = pac->indegrees();
		_levels = pac->nodes_depth();
		for(size_t i=0; i<_indeg.size(); i++) {
			_f1<<_indeg[i]<<"\t"<<_levels[i]<<"\n";
		}
		_indeg.clear(); _levels.clear();
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::levels_outdegrees(Packagegraph *pac){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check2==0){
			_f2.open(_path+"/scatterplot/SlevelVSoutdeg."+_language+".dat",ios::out);
			_f2<<"#outdegrees\tlevels\n";
			_check2=1;
		}
		_outdeg = pac->outdegrees();
		_levels = pac->nodes_depth();
		for(size_t i=0; i<_outdeg.size(); i++) {
			_f2<<_outdeg[i]<<"\t"<<_levels[i]<<"\n";
		}
		_outdeg.clear(); _levels.clear();
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::LeavesIndegrees_LeavesLevels(Packagegraph *pac){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check3==0){
			_f3.open(_path+"/scatterplot/SLeaves_depVSin."+_language+".dat",ios::out);
			_f3<<"#leaves_indegrees\tlevels\n";
			_check3=1;
		}
		_leaves_levels = pac->leaves_depth();
		_leaves_indeg = pac->leaves_indegrees();
		for(size_t i=0; i<_leaves_indeg.size(); i++) {
			_f3<<_leaves_indeg[i]<<"\t"<<_leaves_levels[i]<<"\n";
		}
		_leaves_indeg.clear(); _leaves_levels.clear();
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::depth_Nnodes(Packagegraph *pac){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check4==0){
			_f4.open(_path+"/scatterplot/SdepVSNnodes."+_language+".dat",ios::out);
			_f4<<"#Nnodes\tdepth\tmean_depth\tLeaves_mean_depth\n";
			_check4=1;
		}
		size_t Ngrafi = pac->N();
		for(size_t i=0; i<Ngrafi; i++) {
			_f4<<pac->Nnodes(i)<<"\t"<<pac->depth(i)<<"\t"<<pac->mean_depth(i)<<"\t"<<pac->mean_leaves_depth(i)<<"\n";
		}
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::Vnodes_Nnodes(Packagegraph *pac){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check5==0){
			_f5.open(_path+"/scatterplot/SVnodesVSNnodes."+_language+".dat",ios::out);
			_f5<<"#Nnodes\tVirtualNodes\n";
			_check5=1;
		}
		size_t Ngrafi = pac->N();
		for(size_t i=0; i<Ngrafi; i++) {
			_f5<<pac->Nnodes(i)<<"\t"<<pac->diamanti(i)<<"\t"<<pac->name()<<endl;
		}
	}
}
/*------------------------------------------------------------------*/
void Scatterplot::meanoutdeg_Nnodes_depth(Packagegraph *pac){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check6==0){
			_f6.open(_path+"/scatterplot/SoutdegVSNnodesVSdepth."+_language+".dat",ios::out);
			_f6<<"#Nnodes\tdepth\tmeanoutdegrees\n";
			_check6=1;
		}
		for(size_t i=0; i<pac->N(); i++) {
			_f6<<pac->Nnodes(i)<<"\t"<<pac->depth(i)<<"\t"<<pac->mean_outdeg(i)<<"\n";
		}
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::depth_Nnodes_outdeg(Packagegraph *pac, size_t minN, size_t minL){
	if (_check==0) cerr<<"Scatterplot:: path non dichiarato!"<<endl;
	else {	
		if(_check1==0){
			_f7.open(_path+"/scatterplot/NnodesVSdepthVSoutdeg."+_language+".dat",ios::out);
			_f7<<"#Nndoes\tdepth\toutdeg\n";
			_check1=1;
		}
		for(size_t j=0;j<pac->N();j++){
			if(pac->Nnodes(j)<=minN) continue;
			if(pac->depth(j)<=minL) continue;
				for(size_t i=0; i<pac->Nnodes(j); i++) {
					_f7<<pac->Nnodes(j)<<"\t"<<pac->depth(j)<<"\t"<<pac->outdeg(j,i)<<"\n";
				}
		}
	}
};
/*------------------------------------------------------------------*/
void Scatterplot::clear(){
	_f1.close(); _f2.close(); _f3.close(); _f4.close(); _f5.close(); _f6.close(); _f7.close(); _f8.close(); _f9.close(); _f10.close();
	if(_check==1) system(("cd "+_path+"/scatterplot/; Sorta;").c_str());
	_check=0;
	_check1=0;
	_check2=0;
	_check3=0;
	_check4=0;
	_check5=0;
	_check6=0;
	_check7=0;
	_check8=0;
	_check9=0;
	_check10=0;
};
/*------------------------------------------------------------------*/
