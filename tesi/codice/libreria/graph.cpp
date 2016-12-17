#include "graph.hpp"

/*--------------------------------------------------------------------
 Costruttori
--------------------------------------------------------------------*/
Graph::Graph(): _nodes(NULL), _ordernodes(NULL), _Rordernodes(NULL), _diamonds(0), _diamonds_check(0) {};
/*------------------------------------------------------------------*/
Graph::Graph(const char *edgefile): _ordernodes(NULL), _Rordernodes(NULL), _diamonds(0), _diamonds_check(0) {
	fstream f;
	string help;
	vector<string> from,to;

	f.open(edgefile,ios::in);
	f>>help;
	while(!f.eof()){
		from.push_back(help);
		f>>help;
		to.push_back(help);
		f>>help;
	}
        f.close();

	if (from.size()!=to.size()) {
		cerr<<"Graph:: costruttore - controlla il file di input!"<<endl;
	}
	if (from.size()==0 || to.size()==0) {
		cerr<<"Graph:: costruttore - creazione di grafo mononodo!"<<endl;
		_Nnodes=1;
		_nodes = new Node;
		_roots.push_back(0);
		_leaves.push_back(0);
		_nodes[0].Set_level(1);
		_nodes[0].Set_Rlevel(1);
		_ordernodes=new size_t;
		_ordernodes[0]=0;
		_Rordernodes=new size_t;
		_Rordernodes[0]=0;
	}
	else {
		map<string,size_t> conversione;
		size_t cont=0;
		for(size_t i=0; i<from.size(); i++) {
			if(conversione.find(from[i]) == conversione.end()) {
				conversione[from[i]]=cont;
				cont++;
			}
			if(conversione.find(to[i]) == conversione.end()) {
				conversione[to[i]]=cont;
				cont++;
			}
		}
		_Nnodes = conversione.size();
		_nodes = new Node[_Nnodes];
		//Costruzione del grafo
		for(size_t i=0;i<from.size();i++){
			if(from[i] == to[i]) {
				cerr << "Graph:: set - Loop, padre di se stesso!" << endl;
				continue;	// loooooop :( 
			}
			_nodes[conversione[from[i]]].Add_edge_out(conversione[to[i]]);
			_nodes[conversione[to[i]]].Add_edge_in(conversione[from[i]]);
		}
		find_roots();
		find_connection();
		find_levels();
		find_leaves();
		find_reversed_levels();
	}
};
/*---------------------------------------------------------------------
 Assegnamento
---------------------------------------------------------------------*/
Graph &Graph::operator=(const Graph &obj){
	(*this).clear();
	_Nnodes=obj._Nnodes;
	_leaves=obj._leaves;
	_roots=obj._roots;
	_diamonds=obj._diamonds;
	_diamonds_check=obj._diamonds_check;
	_Kin=obj._Kin;
	_Kout=obj._Kout;
	_ordernodes = new size_t[_Nnodes];
	_Rordernodes = new size_t[_Nnodes];
	_nodes = new Node[_Nnodes];
	for(size_t i=0; i<_Nnodes; i++) {
		_ordernodes[i]=obj._ordernodes[i];
		_Rordernodes[i]=obj._Rordernodes[i];
		_nodes[i]=obj._nodes[i];
	}
	return *this;
};
/*---------------------------------------------------------------------
 Distruttore
---------------------------------------------------------------------*/
Graph::~Graph(){
	if(_nodes!=NULL) {
		if(_Nnodes==1) delete _nodes;
		else delete[] _nodes;
	}
	if(_ordernodes!=NULL) {
		if(_Nnodes==1) delete _ordernodes;
		else delete[] _ordernodes;
	}
	if(_Rordernodes!=NULL) {
		if(_Nnodes==1) delete _Rordernodes;
		else delete[] _Rordernodes;
	}
	_nodes = NULL;
	_ordernodes = NULL;
	_Rordernodes = NULL;
	_leaves.clear();
	_roots.clear();
	_Nnodes = 0;
};
/*---------------------------------------------------------------------
   Settings
---------------------------------------------------------------------*/
void Graph::set(vector<size_t> from, vector<size_t> to, bool connection ){
	clear();
	if (from.size()!=to.size()) {
		cerr<<"Graph:: set - controlla i vettori in input!"<<endl;
	}
	if (from.size()==0 || to.size()==0) {
		cerr<<"Graph:: set - creazione di grafo mononodo!"<<endl;
		_Nnodes=1;
		_nodes = new Node;
		_roots.push_back(0);
		_leaves.push_back(0);
		_nodes[0].Set_level(1);
		_nodes[0].Set_Rlevel(1);
		_ordernodes=new size_t;
		_ordernodes[0]=0;
		_Rordernodes=new size_t;
		_Rordernodes[0]=0;
	}
	else {
		map<size_t,size_t> conversione;
		size_t cont=0;
		for(size_t i=0; i<from.size(); i++) {
			if(conversione.find(from[i]) == conversione.end()) {
				conversione[from[i]]=cont;
				cont++;
			}
			if(conversione.find(to[i]) == conversione.end()) {
				conversione[to[i]]=cont;
				cont++;
			}
		}
		_Nnodes = conversione.size();
		_nodes = new Node[_Nnodes];
		//Costruzione del grafo
		for(size_t i=0;i<from.size();i++){
			if(from[i] == to[i]) {
				cerr << "Graph:: set - Loop, padre di se stesso!" << endl;
				continue;	// loooooop :( 
			}
			_nodes[conversione[from[i]]].Add_edge_out(conversione[to[i]]);
			_nodes[conversione[to[i]]].Add_edge_in(conversione[from[i]]);
		}
		find_roots();
		if(connection==0) find_connection();
		find_levels();
		find_leaves();
		find_reversed_levels();
	}
};
/*---------------------------------------------------------------------*/
void Graph::clear(){
	if(_nodes!=NULL) {
		if(_Nnodes==1) delete _nodes;
		else delete[] _nodes;
	}
	if(_ordernodes!=NULL) {
		if(_Nnodes==1) delete _ordernodes;
		else delete[] _ordernodes;
	}
	if(_Rordernodes!=NULL) {
		if(_Nnodes==1) delete _Rordernodes;
		else delete[] _Rordernodes;
	}
	_nodes = NULL;
	_ordernodes = NULL;
	_Rordernodes = NULL;
	_leaves.clear();
	_roots.clear();
	_Kin.clear();
	_Kout.clear();
	_Nnodes = 0;
	_diamonds_check = 0;
	_diamonds = 0;
};
/*---------------------------------------------------------------------
  Finding ...
---------------------------------------------------------------------*/
void Graph::find_levels(){
	size_t iter_level=1, help;
	vector<size_t> support1, support2;
	//selezionare le root del grafo
	for(size_t i=0;i<_roots.size();i++){
		support1.push_back(_roots[i]);
	}
	//percorrere il grafo top-down per definire i livelli
	while(support1.size()!=0){
		iter_level++;
		for(size_t i=0;i<support1.size();i++){
			for(size_t j=0;j<_nodes[support1[i]].Get_Nsons();j++){
				help=_nodes[support1[i]].Get_son(j);
				_nodes[help].Set_level(iter_level);
				support2.push_back(help);
			}
		}
		support1.clear();
		iter_level++;
		for(size_t i=0;i<support2.size();i++){
			for(size_t j=0;j<_nodes[support2[i]].Get_Nsons();j++){
				help=_nodes[support2[i]].Get_son(j);
				_nodes[help].Set_level(iter_level);
				support1.push_back(help);
			}
		}
		support2.clear();
	}
	//salvo l'indice delle posizioni dei nodi ordinati secondo il loro livello
	_ordernodes=new size_t[_Nnodes];
	for(size_t i=0;i<_Nnodes;i++) _ordernodes[i]=i;
	size_t vettore[_Nnodes];
	for(size_t i=0;i<_Nnodes;i++) vettore[i]=_nodes[i].Get_level();
	quicksort(_Nnodes,vettore,_ordernodes);
};
/*----------------------------------------------------------------------*/
void Graph::find_reversed_levels(){
	size_t iter_level=1, help;
	vector<size_t> support1, support2;
	//selezionare le leaves del grafo
	for(size_t i=0;i<_leaves.size();i++){
		support1.push_back(_leaves[i]);
	}
	//percorrere il grafo down-top per definire i livelli
	while(support1.size()!=0){
		iter_level++;
		for(size_t i=0;i<support1.size();i++){
			for(size_t j=0;j<_nodes[support1[i]].Get_Npar();j++){
				help=_nodes[support1[i]].Get_par(j);
				_nodes[help].Set_Rlevel(iter_level);
				support2.push_back(help);
			}
		}
		support1.clear();
		iter_level++;
		for(size_t i=0;i<support2.size();i++){
			for(size_t j=0;j<_nodes[support2[i]].Get_Npar();j++){
				help=_nodes[support2[i]].Get_par(j);
				_nodes[help].Set_Rlevel(iter_level);
				support1.push_back(help);
			}
		}
		support2.clear();
	}
	//salvo l'indice delle posizioni dei nodi ordinati secondo il loro livello
	_Rordernodes=new size_t[_Nnodes];
	for(size_t i=0;i<_Nnodes;i++) _Rordernodes[i]=i;
	size_t vettore[_Nnodes];
	for(size_t i=0;i<_Nnodes;i++) vettore[i]=_nodes[i].Get_Rlevel();
	quicksort(_Nnodes,vettore,_Rordernodes);
};
/*----------------------------------------------------------------------*/
void Graph::find_leaves(){
	for(size_t i=0;i<_Nnodes;i++) {
		if(_nodes[i].Get_Nsons()==0) {
			_leaves.push_back(i);
			_nodes[i].Set_Rlevel(1);
		}
	}	
};
/*----------------------------------------------------------------------*/
void Graph::find_roots(){
	for(size_t i=0;i<_Nnodes;i++) {
		if(_nodes[i].Get_Npar()==0) {
			_roots.push_back(i);
			_nodes[i].Set_level(1);
		}
	}
};
/*---------------------------------------------------------------------*/
void Graph::find_connection() {
	std::set<size_t> supporto, tosave;
	//cerco componente piu' grande
	for (size_t i=0; i<_roots.size(); i++) {
		if(supporto.find(_roots[i])==supporto.end()) {
			visita(_roots[i], supporto);
			if(supporto.size() > tosave.size()) tosave = supporto;
			supporto.clear();
		}
	}
	if(tosave.size() != _Nnodes) {
		cerr<<"Graph:: Errore! Il grafo non e' connesso (o non ci sono radici)!"<<endl;
		vector<size_t> new_from, new_to;
		for (std::set<size_t>::iterator i = tosave.begin(); i != tosave.end(); i++) {
			for(size_t j=0; j<_nodes[*i].Get_Nsons(); j++){
				new_from.push_back(*i);
				new_to.push_back(_nodes[*i].Get_son(j));
			}
		}
		(*this).clear();
		this->set(new_from,new_to, 1);
	}
}
/*---------------------------------------------------------------------*/
void Graph::find_Kin() {
	std::set<size_t> linkati_up;
	for(size_t i=0; i<_Nnodes; i++) {
		visita_up(i,linkati_up);
		_Kin.push_back(linkati_up.size()-1);
		linkati_up.clear();
	}

}
/*---------------------------------------------------------------------*/
void Graph::find_Kout() {
	std::set<size_t> linkati_down;
	for(size_t i=0; i<_Nnodes; i++) {
		visita_down(i,linkati_down);
		_Kout.push_back(linkati_down.size()-1);
		linkati_down.clear();
	}
}
/*---------------------------------------------------------------------*/
void Graph::find_diamonds() {
	std::set<size_t> linkati;
	std::set<size_t> diamanti;
	for(size_t i=0; i<_Nnodes; i++) {
		visita_diamond(i,i,linkati, diamanti);
		linkati.clear();
	}
	_diamonds = diamanti.size();
	_diamonds_check = 1;
}
/*---------------------------------------------------------------------
  Visiting ...
---------------------------------------------------------------------*/
//per vedere se il grafo e' connesso
void Graph::visita(size_t node, std::set<size_t> &visitati) {
	std::set<size_t> linkati;
	visitati.insert(node);
	for (size_t j=0; j<_nodes[node].Get_Nsons(); j++) {
		linkati.insert(_nodes[node].Get_son(j));
	}
	for (size_t j=0; j<_nodes[node].Get_Npar(); j++) {
		linkati.insert(_nodes[node].Get_par(j));
	}
	for (std::set<size_t>::iterator j = linkati.begin(); j != linkati.end(); j++) {
		if(visitati.find(*j) == visitati.end()) {
			visita(*j, visitati);
		}
	}
};
/*---------------------------------------------------------------------*/
void Graph::visita_up(size_t node, std::set<size_t> &visitati) {
	std::set<size_t> linkati;
	visitati.insert(node);
	for (size_t j=0; j<_nodes[node].Get_Npar(); j++) {
		linkati.insert(_nodes[node].Get_par(j));
	}
	for (std::set<size_t>::iterator j = linkati.begin(); j != linkati.end(); j++) {
		if(visitati.find(*j) == visitati.end()) {
			visita_up(*j, visitati);
		}
	}
};
/*---------------------------------------------------------------------*/
void Graph::visita_down(size_t node, std::set<size_t> &visitati) {
	std::set<size_t> linkati;
	visitati.insert(node);
	for (size_t j=0; j<_nodes[node].Get_Nsons(); j++) {
		linkati.insert(_nodes[node].Get_son(j));
	}
	for (std::set<size_t>::iterator j = linkati.begin(); j != linkati.end(); j++) {
		if(visitati.find(*j) == visitati.end()) {
			visita_down(*j, visitati);
		}
	}
};
/*---------------------------------------------------------------------*/
void Graph::visita_diamond(size_t analyzed, size_t node, std::set<size_t> &visitati, std::set<size_t> &diamanti) {
	std::set<size_t> linkati;
	visitati.insert(node);
	for (size_t j=0; j<_nodes[node].Get_Npar(); j++) {
		linkati.insert(_nodes[node].Get_par(j));
	}
	if (_diamonds_check == 0 ) {
		for (std::set<size_t>::iterator j = linkati.begin(); j != linkati.end(); j++) {
			if(visitati.find(*j) == visitati.end()) {
				visita_diamond(analyzed, *j, visitati, diamanti);
			}
			else {
				diamanti.insert(analyzed);
				break;
			}
		}
	}
	
};
/*---------------------------------------------------------------------
  Get
---------------------------------------------------------------------*/
size_t Graph::brothers(size_t level) {
	size_t cont=0;
	for(size_t i=0;i<_Nnodes;i++){
		if(_nodes[_ordernodes[i]].Get_level()==level) cont++;;
		if(_nodes[_ordernodes[i]].Get_level()>level) break;
	}
	return cont;
}
/*---------------------------------------------------------------------*/
size_t Graph::Rbrothers(size_t level) {
	size_t cont=0;
	for(size_t i=0;i<_Nnodes;i++){
		if(_nodes[_Rordernodes[i]].Get_Rlevel()==level) cont++;;
		if(_nodes[_Rordernodes[i]].Get_Rlevel()>level) break;
	}
	return cont;
}
/*---------------------------------------------------------------------*/
size_t Graph::depth() {
	return _nodes[_ordernodes[_Nnodes-1]].Get_level();
}
/*---------------------------------------------------------------------*/
size_t Graph::Nnodes() {
	return _Nnodes;
}
/*---------------------------------------------------------------------*/
size_t Graph::outdeg(size_t nodo) {
	return _nodes[_ordernodes[nodo]].Get_Nsons();
}
/*---------------------------------------------------------------------*/
size_t Graph::indeg(size_t nodo) {
	return _nodes[_ordernodes[nodo]].Get_Npar();
}
/*---------------------------------------------------------------------*/
size_t Graph::Nnodes(size_t level) {
	size_t control=0, sum=0;
	for(size_t i=0;i<_Nnodes;i++){
		control=_nodes[_ordernodes[i]].Get_level();
		if(control==level) sum++;
		if(control>level) break;
	}
	return sum;
}
/*---------------------------------------------------------------------*/
size_t Graph::RNnodes(size_t level) {
	size_t control=0, sum=0;
	for(size_t i=0;i<_Nnodes;i++){
		control=_nodes[_Rordernodes[i]].Get_Rlevel();
		if(control==level) sum++;
		if(control>level) break;
	}
	return sum;
}
/*---------------------------------------------------------------------*/
size_t Graph::diamonds() {
	if (_diamonds_check == 0) {
		find_diamonds();
	}
	return _diamonds;
};
/*---------------------------------------------------------------------*/
size_t Graph::Nleaves() {
	return _leaves.size();
}
/*---------------------------------------------------------------------*/
vector<size_t> Graph::leaves_depth(){
	vector<size_t> depths;
	for(size_t i=0;i<_leaves.size();i++)
		 depths.push_back(_nodes[_leaves[i]].Get_level());
	return depths;
};
/*---------------------------------------------------------------------*/
vector<size_t> Graph::nodes_depth(){
	vector<size_t> depths;
	for(size_t i=0;i<_Nnodes;i++)
		 depths.push_back(_nodes[i].Get_level());
	return depths;
};
/*---------------------------------------------------------------------*/
vector<size_t> Graph::leaves_indegrees(){
	vector<size_t> indegrees;
	for(size_t i=0;i<_leaves.size();i++)
		 indegrees.push_back(_nodes[_leaves[i]].Get_Npar());
	return indegrees;
};
/*---------------------------------------------------------------------*/
vector<size_t> Graph::roots_outdegrees(){
	vector<size_t> outdegrees;
	for(size_t i=0;i<_roots.size();i++)
		 outdegrees.push_back(_nodes[_roots[i]].Get_Nsons());
	return outdegrees;
};
/*---------------------------------------------------------------------*/
vector<size_t> Graph::indegrees(){
	vector<size_t> indegrees;
	for(size_t i=0;i<_Nnodes;i++)
		 indegrees.push_back(_nodes[i].Get_Npar());
	return indegrees;
};
/*---------------------------------------------------------------------*/
vector<size_t> Graph::outdegrees(){
	vector<size_t> outdegrees;
	for(size_t i=0;i<_Nnodes;i++)
		 outdegrees.push_back(_nodes[i].Get_Nsons());
	return outdegrees;
};
/*---------------------------------------------------------------------*/
vector<double> Graph::mean_Routdegrees(){
	vector<double> outdegrees;
	for(size_t i=0;i<depth();i++)
		 outdegrees.push_back(mean_Routdeg(i+1));
	return outdegrees;
};
/*---------------------------------------------------------------------*/
vector<double> Graph::mean_outdegrees(){
	vector<double> outdegrees;
	for(size_t i=0;i<depth();i++)
		 outdegrees.push_back(mean_outdeg(i+1));
	return outdegrees;
};
/*---------------------------------------------------------------------*/
vector<size_t> Graph::Kin(){
	find_Kin();
	return _Kin;
}
/*---------------------------------------------------------------------*/
vector<size_t> Graph::Kout(){
	find_Kout();
	return _Kout;
}
/*---------------------------------------------------------------------
 Statistics
---------------------------------------------------------------------*/
double Graph::mean_depth(){
	size_t sum=0;
	for(size_t i=0;i<_Nnodes;i++)
		sum+=_nodes[i].Get_level();
	return double(sum)/_Nnodes;
};
/*---------------------------------------------------------------------*/
double Graph::mean_leaves_depth(){
	size_t sum=0;
	for(size_t i=0;i<_leaves.size();i++)
		sum+=_nodes[_leaves[i]].Get_level();
	return double(sum)/_leaves.size();
};
/*---------------------------------------------------------------------*/
double Graph::mean_Rdepth(){
	size_t sum=0;
	for(size_t i=0;i<_Nnodes;i++)
		sum+=_nodes[i].Get_Rlevel();
	return double(sum)/_Nnodes;
};
/*---------------------------------------------------------------------*/
double Graph::mean_outdeg(){
	size_t sum=0,cont=0;
	for(size_t i=0;i<_Nnodes;i++){
		sum+=_nodes[i].Get_Nsons();
		cont++;
	}
	return double(sum)/cont;
};
/*---------------------------------------------------------------------*/
double Graph::mean_outdeg(size_t level){
	size_t sum=0,cont=0;
	for(size_t i=0;i<_Nnodes;i++){
		if(_nodes[i].Get_level()==level){
			sum+=_nodes[i].Get_Nsons();
			cont++;
		}
	}
	return double(sum)/cont;
};
/*---------------------------------------------------------------------*/
double Graph::mean_Routdeg(size_t level){
	size_t sum=0,cont=0;
	for(size_t i=0;i<_Nnodes;i++){
		if(_nodes[i].Get_Rlevel()==level){
			sum+=_nodes[i].Get_Nsons();
			cont++;
		}
	}
	return double(sum)/cont;
};
/*---------------------------------------------------------------------*/
double Graph::cost(double lambda) {
	double sum = 0.;
	for(size_t i=0;i<_Nnodes;i++)
		sum += cost(i, lambda);
	return sum/_Nnodes;
};
/*---------------------------------------------------------------------*/
double Graph::cost(size_t nodo, double lambda) {
	size_t Npar = _nodes[nodo].Get_Npar();
	size_t kout = 0;
	for(size_t i=0;i<Npar;i++){
		size_t par = _nodes[nodo].Get_par(i);
		kout += _nodes[par].Get_Nsons();		
	}
	if(Npar == 0) return 1.0;
	else return 1.0 - exp(-lambda*kout);	
};
/*---------------------------------------------------------------------*/
double Graph::recursive_cost(double lambda) {
	double sum = 0.;
	for(size_t i=0;i<_Nnodes;i++)
		sum += recursive_cost(i, lambda);
	return sum/_Nnodes;
};
/*---------------------------------------------------------------------*/
double Graph::recursive_cost(size_t nodo, double lambda) {
	size_t Npar = _nodes[nodo].Get_Npar();
	size_t kout = 0;
	double prev = 0.0;
	for(size_t i=0;i<Npar;i++){
		size_t par = _nodes[nodo].Get_par(i);
		kout += _nodes[par].Get_Nsons();		
		prev += recursive_cost(par, lambda);
	}
	prev /= Npar;
	if(Npar == 0) return 1.0;
	else return prev - exp(-lambda*kout);	
};
/*---------------------------------------------------------------------
  Miscellaneous
---------------------------------------------------------------------*/
void Graph::HTD(double **scores, string **namescores, size_t nrows){
	size_t position, Npar, dad;
	//applico l'algoritmo top-down al grafo
	for(size_t i=0;i<_Nnodes;i++){
		position=_ordernodes[i];
 		Npar=_nodes[position].Get_Npar();
		for(size_t k=0;k<nrows;k++){
			for(size_t j=0;j<Npar;j++){
				dad=_nodes[position].Get_par(j);
				if(scores[k][position] > scores[k][dad]){
					scores[k][position]=scores[k][dad];
					namescores[k][position]=namescores[k][dad];
				}
			}
		}
	}
};
/*---------------------------------------------------------------------*/
std::ostream &operator<<( std::ostream &os,  Graph &g){
	os<<0<<endl;
	for(size_t i=0; i<g._Nnodes; i++){
		for(size_t j=0; j<g._nodes[i].Get_Nsons(); j++){
			os<< i+1 << "\t" << g._nodes[i].Get_son(j)+1<< "\n";
		}
	}
	return os;
};
/*---------------------------------------------------------------------*/
