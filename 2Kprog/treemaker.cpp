/*--------------------------------------------------------------------






--------------------------------------------------------------------*/
/*==================================================================*/

#include "treemaker.hpp"

/*--------------------------------------------------------------------
 Costruttore
--------------------------------------------------------------------*/
TreeMaker::TreeMaker() {
	r = gsl_rng_alloc(gsl_rng_default);
//	gsl_rng_set(r,time(NULL));
	struct timeval deltatime;
	gettimeofday(&deltatime, NULL);
	gsl_rng_set(r,deltatime.tv_usec);
};
/*--------------------------------------------------------------------
 Distruttore
--------------------------------------------------------------------*/
TreeMaker::~TreeMaker(){
	gsl_rng_free(r);
};
/*--------------------------------------------------------------------
 Functions for Time
--------------------------------------------------------------------*/
void TreeMaker::RussianTree_Time(size_t NrootsInit, size_t Nsteps, double indeg_mean, vector<size_t> &from, vector<size_t> &to){
	from.clear();
	to.clear();
	size_t newnode=NrootsInit+1, rho, dad;

	for(size_t i=0; i<Nsteps;i++){
		rho = gsl_ran_poisson (r, indeg_mean);
		for(size_t j=0; j<rho; j++) {
			dad = floor(gsl_ran_flat (r, 1.0, newnode));
			from.push_back(dad);
			to.push_back(newnode);
		}
		newnode++;
	}
};
/*------------------------------------------------------------------*/
void TreeMaker::ReversedRussianTree_Time(size_t NleavesInit, size_t Nsteps, double outdeg_mean, vector<size_t> &from, vector<size_t> &to){
	from.clear();
	to.clear();
	size_t newnode=NleavesInit+1, rho, son;

	for(size_t i=0; i<Nsteps;i++){
		rho = gsl_ran_poisson (r, outdeg_mean);
		for(size_t j=0; j<rho; j++) {
			son = floor(gsl_ran_flat (r, 1.0, newnode));
			from.push_back(newnode);
			to.push_back(son);
		}
		newnode++;
	}
};
/*------------------------------------------------------------------*/
void TreeMaker::YuleTree_Time(size_t Nsteps, double outdeg_mean, vector<size_t> &from, vector<size_t> &to){
	from.clear();
	to.clear();
	size_t selected = 1, generati = 1, rho=0, exrho=0;

	while(rho==0) rho = gsl_ran_poisson (r, outdeg_mean);

	for(size_t j=0; j<Nsteps;j++){
		if (rho!=0) exrho=rho;
		for(size_t i=0; i<rho; i++) {
			generati++;
			from.push_back(selected);
			to.push_back(generati);
		}
		rho = gsl_ran_poisson (r, outdeg_mean);
		if(selected == generati) {
			selected -= exrho;
			j--;
		}
		selected++;
	}
};
/*------------------------------------------------------------------*/
Graph *TreeMaker::YuleTree_Time(size_t Nsteps, double outdeg_mean) {
	vector<size_t> from, to;
	YuleTree_Time(Nsteps, outdeg_mean, from, to);
	Graph *g=new Graph;
	g->set(from, to);
	from.clear();
	to.clear();
	return g;
}
/*------------------------------------------------------------------*/
Graph *TreeMaker::RussianTree_Time(size_t NrootsInit, size_t Nsteps, double indeg_mean) {
	vector<size_t> from, to;
	RussianTree_Time(NrootsInit, Nsteps, indeg_mean, from, to);
	Graph *g=new Graph;
	g->set(from, to);
	from.clear();
	to.clear();
	return g;
}
/*------------------------------------------------------------------*/
Graph *TreeMaker::ReversedRussianTree_Time(size_t NleavesInit, size_t Nsteps, double outdeg_mean) {
	vector<size_t> from, to;
	ReversedRussianTree_Time(NleavesInit, Nsteps, outdeg_mean, from, to);
	Graph *g=new Graph;
	g->set(from, to);
	from.clear();
	to.clear();
	return g;
}
/*--------------------------------------------------------------------
 Functions
--------------------------------------------------------------------*/
void TreeMaker::RussianTree_Nodes(size_t NrootsInit, size_t Nnodes, double indeg_mean, vector<size_t> &from, vector<size_t> &to){
	from.clear();
	to.clear();
	std::set<size_t> linkati;
	size_t newnode=NrootsInit+1, rho, dad;

	while(linkati.size() <= Nnodes) {
		rho = 1;//gsl_ran_poisson (r, indeg_mean);
		for(size_t j=0; j<rho; j++) {
			dad = floor(gsl_ran_flat (r, 1.0, newnode));
			from.push_back(dad);
			linkati.insert(dad);
			to.push_back(newnode);
			linkati.insert(newnode);
			if (linkati.size() >= Nnodes) return;
		}
		newnode++;
	}
};
/*------------------------------------------------------------------*/
void TreeMaker::ReversedRussianTree_Nodes(size_t NleavesInit, size_t Nnodes, double outdeg_mean, vector<size_t> &from, vector<size_t> &to){
	from.clear();
	to.clear();
	std::set<size_t> linkati;
	size_t newnode=NleavesInit+1, rho, son;

	while(linkati.size() <= Nnodes) {
		rho = gsl_ran_poisson (r, outdeg_mean);
		for(size_t j=0; j<rho; j++) {
			son = floor(gsl_ran_flat (r, 1.0, newnode));
			from.push_back(newnode);
			linkati.insert(newnode);
			to.push_back(son);
			linkati.insert(son);
//			cerr << newnode << "\t" << son << endl;
			if (linkati.size() >= Nnodes) return;
		}
		newnode++;
	}
};
/*------------------------------------------------------------------*/
void TreeMaker::YuleTree_Nodes(size_t Nnodes, double outdeg_mean, vector<size_t> &from, vector<size_t> &to){
	from.clear();
	to.clear();
	size_t selected = 1, generati = 1, rho=0, exrho=0;

	while(rho==0) rho = gsl_ran_poisson (r, outdeg_mean);

	while(generati != Nnodes) {
		if (rho!=0) exrho=rho;
		for(size_t i=0; i<rho; i++) {
			generati++;
			from.push_back(selected);
			to.push_back(generati);
//cerr<<selected<<"\t"<<generati<<"\n";
			if (generati==Nnodes) break;
		}
		rho = gsl_ran_poisson (r, outdeg_mean);
		if(selected == generati) {
			selected -= exrho;
		}
		selected++;
	}
};
/*------------------------------------------------------------------*/
Graph *TreeMaker::YuleTree_Nodes(size_t Nnodes, double outdeg_mean) {
	vector<size_t> from, to;
	YuleTree_Nodes(Nnodes, outdeg_mean, from, to);
	Graph *g=new Graph;
	g->set(from, to);
	from.clear();
	to.clear();
	return g;
}
/*------------------------------------------------------------------*/
Graph *TreeMaker::RussianTree_Nodes(size_t NrootsInit, size_t Nnodes, double indeg_mean) {
	vector<size_t> from, to;
	RussianTree_Nodes(NrootsInit, Nnodes, indeg_mean, from, to);
	Graph *g=new Graph;
	g->set(from, to);
	from.clear();
	to.clear();
	return g;
}
/*------------------------------------------------------------------*/
Graph *TreeMaker::ReversedRussianTree_Nodes(size_t NleavesInit, size_t Nnodes, double outdeg_mean) {
	vector<size_t> from, to;
	ReversedRussianTree_Nodes(NleavesInit, Nnodes, outdeg_mean, from, to);
	Graph *g=new Graph;
	g->set(from, to);
	from.clear();
	to.clear();
	return g;
}
/*------------------------------------------------------------------*/
void TreeMaker::MCTree(size_t NleavesInit, size_t Nsequence, size_t Nsymbols, vector<size_t> &from, vector<size_t> &to) {
	from.clear();
	to.clear();
	_from.clear();
	_to.clear();

	_NleavesInit=NleavesInit;
	_Nsequence=Nsequence;
	_Nsymbols=Nsymbols;

	unordered_set<size_t> nodi[_NleavesInit];
	vector<size_t> supporto;
	vector<vector<size_t>> split1;

	for(size_t i=0;i<_NleavesInit;i++) supporto.push_back(i);

	// GENERO I NODI //
	for(size_t i=0; i<_NleavesInit; i++){
//		for(size_t j=0; j<(gsl_ran_flat(r, 1.0, Nsequence+1)); j++){
		for(size_t j=0; j<_Nsequence; j++){
riprovaci:
			nodi[i].insert(RandomSymbol());
			if(nodi[i].size()!=j+1) goto riprovaci;
		}
//cout<<nodi[i].size()<<endl;
	}

	// matrice dei simboli //
	_presenza=new bool*[_NleavesInit];
	for(size_t i=0; i<_NleavesInit; i++) _presenza[i]=new bool[_Nsymbols];

	for(size_t i=0; i<_NleavesInit; i++){
		for(size_t j=0; j<Nsymbols; j++){
			if(nodi[i].find(j+1)!=nodi[i].end()){
				_presenza[i][j]=1;
			}
			else _presenza[i][j]=0;
		}
	}

	size_t mas=0;
	size_t cont=0;
	size_t sim=0;
	for(size_t j=0; j<_Nsymbols; j++){
		for(size_t i=0; i<supporto.size(); i++){
			if(_presenza[supporto[i]][j]) cont++;
		}
		if(mas<cont) {
			mas=cont;
			sim=j;
		}
		cont=0;
	}

	vector<size_t> add;	
	split1.push_back(add);
	for(size_t k=0; k<supporto.size(); k++){
		if(_presenza[supporto[k]][sim]){
			split1[0].push_back(supporto[k]);
		}
	}
	_Nnodes=split1[0].size();

	size_t esclude=0, esclude2=0, nextnode=1, newnode=1;
	size_t foglie=0;

	Ricorrente(split1, esclude, esclude2, nextnode, newnode, foglie);

	from=_from;
	to=_to;
	_from.clear();
	_to.clear();
	
	for(size_t j=0; j<_NleavesInit; j++) delete _presenza[j];
	delete[] _presenza;
};
/*------------------------------------------------------------------*/
Graph *TreeMaker::MCTree(size_t NleavesInit, size_t Nsequence, size_t Nsymbols){
	vector<size_t> from, to;
	MCTree(NleavesInit, Nsequence, Nsymbols, from, to);
	Graph *g=new Graph;
	g->set(from, to);
	from.clear();
	to.clear();
	return g;
}
/*------------------------------------------------------------------*/
size_t TreeMaker::RandomSymbol(){
	return floor(gsl_ran_flat (r, 1.0, _Nsymbols+1));
//return floor(gsl_ran_gaussian (r, 100))+(_Nsymbols/2.);
};
/*------------------------------------------------------------------*/
void TreeMaker::Simboloricorrente(vector<size_t> &supporto, vector<vector<size_t>> &splittati){
	vector<size_t> ecco, esclusi;
	bool chk;
	size_t ciclo=0, max_sum, massimo, contatore;
	do {
		massimo=0;
		contatore=0;
		for(size_t j=0; j<_Nsymbols; j++){
			chk=0;
			for(size_t h=0; h<ecco.size(); h++){
				if(j==ecco[h]) {
					chk=1;
					break;
				}
			}
			if(chk) continue;
			for(size_t i=0; i<supporto.size(); i++){
				if(_presenza[supporto[i]][j]) contatore++;
			}
			if(massimo<contatore) {
				massimo=contatore;
				max_sum=j;
			}
			contatore=0;
		}
		if(massimo==0) {
			vector<size_t> add;	
			if(ciclo>0){
				splittati.push_back(add);
				for(size_t k=0; k<supporto.size(); k++){
					splittati[ciclo].push_back(supporto[k]);
				}
			}
			if(ciclo==0){
				for(size_t k=0; k<supporto.size(); k++){
					splittati.push_back(add);
					splittati[ciclo].push_back(supporto[k]);
					ciclo++;
				}
			}
			break;
		}
		vector<size_t> add;	
		splittati.push_back(add);
		for(size_t k=0; k<supporto.size(); k++){
			if(_presenza[supporto[k]][max_sum]){
				splittati[ciclo].push_back(supporto[k]);
_presenza[supporto[k]][max_sum]=0;
			}
			else{
				esclusi.push_back(supporto[k]);
			}
		}
		supporto=esclusi;
		esclusi.clear();
		ciclo++;
		if(supporto.size()==0) break;
	} while(1);
};
/*------------------------------------------------------------------*/
void TreeMaker::Ricorrente(vector<vector<size_t>> split1, size_t &esclude, size_t &esclude2, size_t nextnode, size_t &newnode, size_t &foglie){
	vector<vector<size_t>> split2;
	vector<vector<size_t>> split3;
	for(size_t i=0;i<split1.size();i++){
		if(split1[i].size()==1) {
			nextnode++;
			foglie++;
			if(foglie==_Nnodes) return;//exit(0);
		}
		if(split1[i].size()>1){
			split2.clear();
			Simboloricorrente(split1[i], split2);
			for(size_t r=0;r<split2.size();r++){
				newnode++;
				_from.push_back(nextnode);
				_to.push_back(newnode);
			}
			nextnode++;
		}
		for(size_t j=0;j<split2.size();j++) {
			if(split2[j].size()>1)	split3.push_back(split2[j]);
			else{
				esclude2++;
				foglie++;
				if(foglie==_Nnodes) return;//exit(0);
			}
		}
	}
	nextnode+=esclude;
	esclude=esclude2;
	esclude2=0;
	if(split2.size()!=0) Ricorrente(split3, esclude, esclude2, nextnode, newnode, foglie);
	else return;
};
/*------------------------------------------------------------------*/

