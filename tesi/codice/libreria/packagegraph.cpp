#include "packagegraph.hpp"

/*--------------------------------------------------------------------
 Costruttori
--------------------------------------------------------------------*/
Packagegraph::Packagegraph(): _Ngrafi(0){};
/*------------------------------------------------------------------*/
Packagegraph::Packagegraph(const char *edgefile) {
	fstream f;
	size_t help;
	vector<size_t> edges1,edges2;
	Graph *graphelp;
	_nome=edgefile; _nome.pop_back(); _nome.pop_back(); _nome.pop_back(); _nome.pop_back();
	f.open(edgefile,ios::in);
	f>>help;
	f>>help;
	while(!f.eof()){
		if (help!=0) {
			edges1.push_back(help);
			f>>help;
			edges2.push_back(help);
			f>>help;
		}
		else {
			graphelp = new Graph();
			if(edges1.size()==0 || edges2.size()==0) {
				f>>help;
				continue;
			}
			graphelp->set(edges1,edges2);
			_grafi.push_back(graphelp);
			edges1.clear();
			edges2.clear();
			f>>help;
		}
	}
        f.close();
	if(edges1.size()!=0 && edges2.size()!=0) {
		graphelp = new Graph();
		graphelp->set(edges1,edges2);
		_grafi.push_back(graphelp);
	}
	edges1.clear();
	edges2.clear();
	_Ngrafi=_grafi.size();
};
/*---------------------------------------------------------------------
 Assegnamento
---------------------------------------------------------------------*/
Packagegraph &Packagegraph::operator=(Packagegraph &obj){
	_Ngrafi=obj._Ngrafi;
	Graph* help;
	for(size_t i=0; i<_Ngrafi; i++) {
		help=new Graph();
		*help=*(obj._grafi[i]);
		_grafi.push_back(help);
	}
	return *this;
};
/*---------------------------------------------------------------------
 Distruttore
---------------------------------------------------------------------*/
Packagegraph::~Packagegraph(){
	for(size_t i=0;i<_Ngrafi; i++){
		delete _grafi[i];
	}
	_grafi.clear();
};
/*---------------------------------------------------------------------
 Settings
---------------------------------------------------------------------*/
/*-------------------------------------------------------------------*/
void Packagegraph::add(Graph *g) {
	_grafi.push_back(g);
	_Ngrafi=_grafi.size();
};
/*-------------------------------------------------------------------*/
void Packagegraph::clear() {
	for(size_t i=0;i<_Ngrafi; i++){
		delete _grafi[i];
	}
	_grafi.clear();
	_Ngrafi=0;
	_nome="";
};
/*---------------------------------------------------------------------
 Get
---------------------------------------------------------------------*/
string Packagegraph::name() {
	return _nome;
};
/*-------------------------------------------------------------------*/
size_t Packagegraph::N() {
	return _Ngrafi;
};
/*-------------------------------------------------------------------*/
size_t Packagegraph::Nnodes(size_t i) {
	return _grafi[i]->Nnodes();
};
/*-------------------------------------------------------------------*/
size_t Packagegraph::depth(size_t i) {
	return _grafi[i]->depth();
};
/*-------------------------------------------------------------------*/
size_t Packagegraph::outdeg(size_t grafo,size_t nodo){
	return _grafi[grafo]->outdeg(nodo);
};
/*-------------------------------------------------------------------*/
size_t Packagegraph::indeg(size_t grafo,size_t nodo){
	return _grafi[grafo]->indeg(nodo);
};
/*---------------------------------------------------------------------
 Set
---------------------------------------------------------------------*/
void Packagegraph::set_name(string name) {
	_nome=name;
};
/*---------------------------------------------------------------------
 Quantities
---------------------------------------------------------------------*/
size_t Packagegraph::max_depth() {
	size_t max = depth(0);
	for(size_t i=0; i<_Ngrafi; i++)
		max = _max(depth(i),max);
	return max;
};
/*-------------------------------------------------------------------*/
size_t Packagegraph::Nnodes(size_t i, size_t level) {
	return _grafi[i]->Nnodes(level);
};
/*-------------------------------------------------------------------*/
size_t Packagegraph::RNnodes(size_t i, size_t level) {
	return _grafi[i]->RNnodes(level);
};
/*-------------------------------------------------------------------*/
size_t Packagegraph::Nleaves(size_t grafo) {
	return _grafi[grafo]->Nleaves();
};
/*---------------------------------------------------------------------
 Order parameters
---------------------------------------------------------------------*/
double Packagegraph::cost(size_t grafo, double lambda) {
	return _grafi[grafo]->cost(lambda);
};
/*-------------------------------------------------------------------*/
double Packagegraph::recursive_cost(size_t grafo, double lambda) {
	return _grafi[grafo]->recursive_cost(lambda);
};
/*-------------------------------------------------------------------*/
size_t Packagegraph::diamanti() {
	size_t help=0;
	for(size_t i=0;i<_Ngrafi; i++){
		help+=_grafi[i]->diamonds();
	}
	return help;
};
/*-------------------------------------------------------------------*/
size_t Packagegraph::diamanti(size_t i) {
	return _grafi[i]->diamonds();
};
/*---------------------------------------------------------------------
 Means
---------------------------------------------------------------------*/
double Packagegraph::mean_Nnodes(){
	double sum=0;
	for(size_t i=0; i<_Ngrafi; i++)
		sum+=_grafi[i]->Nnodes();
	return sum/_Ngrafi;
};
/*-------------------------------------------------------------------*/
double Packagegraph::mean_depth(){
	double sum=0;
	for(size_t i=0; i<_Ngrafi; i++)
		sum+=_grafi[i]->depth();
	return sum/_Ngrafi;
};
/*-------------------------------------------------------------------*/
double Packagegraph::mean_outdeg(size_t grafo){
	return _grafi[grafo]->mean_outdeg();
};
/*-------------------------------------------------------------------*/
double Packagegraph::mean_meandepth(){
	double sum=0;
	for(size_t i=0; i<_Ngrafi; i++)
		sum+=_grafi[i]->mean_depth();
	return sum/_Ngrafi;
};
/*-------------------------------------------------------------------*/
double Packagegraph::mean_depth(size_t i){
	return _grafi[i]->mean_depth();
};
/*-------------------------------------------------------------------*/
double Packagegraph::mean_leaves_depth(){
	double sum=0;
	for(size_t i=0; i<_Ngrafi; i++)
		sum+=_grafi[i]->mean_leaves_depth();
	return sum/_Ngrafi;
};
/*-------------------------------------------------------------------*/
double Packagegraph::mean_leaves_depth(size_t i){
	return _grafi[i]->mean_leaves_depth();
};
/*---------------------------------------------------------------------
 Distributions
---------------------------------------------------------------------*/
vector<size_t> Packagegraph::leaves_depth(size_t i){
	return _grafi[i]->leaves_depth();
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::brothers(size_t graph){
	vector<size_t> out;
	for(size_t i=0;i<_grafi[graph]->depth();i++) {
		out.push_back(_grafi[graph]->brothers(i+1));
	}
	return out;
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::Rbrothers(size_t graph){
	vector<size_t> out;
	for(size_t i=0;i<_grafi[graph]->depth();i++) {
		out.push_back(_grafi[graph]->Rbrothers(i+1));
	}
	return out;
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::leaves_depth(){
	vector<size_t> out;
	for(size_t i=0;i<_Ngrafi;i++) {
		vector<size_t> temp = leaves_depth(i);
		for(size_t j=0; j<temp.size(); j++)
			out.push_back(temp[j]);
	}
	return out;
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::nodes_depth(size_t i){
	return _grafi[i]->nodes_depth();
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::nodes_depth(){
	vector<size_t> out;
	for(size_t i=0;i<_Ngrafi;i++) {
		vector<size_t> temp = nodes_depth(i);
		for(size_t j=0; j<temp.size(); j++)
			out.push_back(temp[j]);
	}
	return out;
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::leaves_indegrees(size_t i){
	return _grafi[i]->leaves_indegrees();
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::leaves_indegrees(){
	vector<size_t> out;
	for(size_t i=0;i<_Ngrafi;i++) {
		vector<size_t> temp = leaves_indegrees(i);
		for(size_t j=0; j<temp.size(); j++)
			out.push_back(temp[j]);
	}
	return out;
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::roots_outdegrees(size_t i){
	return _grafi[i]->roots_outdegrees();
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::roots_outdegrees(){
	vector<size_t> out;
	for(size_t i=0;i<_Ngrafi;i++) {
		vector<size_t> temp = roots_outdegrees(i);
		for(size_t j=0; j<temp.size(); j++)
			out.push_back(temp[j]);
	}
	return out;
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::indegrees(size_t i){
	return _grafi[i]->indegrees();
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::indegrees(){
	vector<size_t> out;
	for(size_t i=0;i<_Ngrafi;i++) {
		vector<size_t> temp = indegrees(i);
		for(size_t j=0; j<temp.size(); j++)
			out.push_back(temp[j]);
	}
	return out;
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::outdegrees(size_t i){
	return _grafi[i]->outdegrees();
};
/*-------------------------------------------------------------------*/
vector<double> Packagegraph::mean_Routdegrees(size_t grafo){
	return _grafi[grafo]->mean_Routdegrees();
};
/*-------------------------------------------------------------------*/
vector<double> Packagegraph::mean_outdegrees(size_t grafo){
	return _grafi[grafo]->mean_outdegrees();
};
/*-------------------------------------------------------------------*/
vector<size_t> Packagegraph::outdegrees(){
	vector<size_t> out;
	for(size_t i=0;i<_Ngrafi;i++) {
		vector<size_t> temp = outdegrees(i);
		for(size_t j=0; j<temp.size(); j++)
			out.push_back(temp[j]);
	}
	return out;
};
/*-------------------------------------------------------------------*/
