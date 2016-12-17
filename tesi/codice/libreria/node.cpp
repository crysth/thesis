#include "node.hpp"

/*--------------------------------------------------------------------
 Costruttore
--------------------------------------------------------------------*/
Node::Node(): _level(0), _Rlevel(0) {};
/*---------------------------------------------------------------------
 Assegnamento
---------------------------------------------------------------------*/
Node &Node::operator=(Node &obj){
	_edgein=obj._edgein;
	_edgeout=obj._edgeout;
	_level=obj._level;
	_Rlevel=obj._Rlevel;
	return *this;
};
/*--------------------------------------------------------------------
 Distruttore
--------------------------------------------------------------------*/
Node::~Node(){
	_edgein.clear();
	_edgeout.clear();
};
/*--------------------------------------------------------------------
  Functions
--------------------------------------------------------------------*/
void Node::Add_edge_in(size_t number){
	bool found = false;
	for(size_t i=0; i<_edgein.size(); i++) {
		if(number == _edgein[i]) found = true;
	}
	if(!found) {
		_edgein.push_back(number);
	}
};
/*------------------------------------------------------------------*/
void Node::Add_edge_out(size_t number){
	bool found = false;
	for(size_t i=0; i<_edgeout.size(); i++) {
		if(number == _edgeout[i]) found = true;
	}
	if(!found) {
		_edgeout.push_back(number);
	}
};
/*--------------------------------------------------------------------
  Set
--------------------------------------------------------------------*/
void Node::Set_level(size_t level){
	if(_level<level) _level=level;
};
/*------------------------------------------------------------------*/
void Node::Set_Rlevel(size_t Rlevel){
	if(_Rlevel<Rlevel) _Rlevel=Rlevel;
};
/*--------------------------------------------------------------------
  Get
--------------------------------------------------------------------*/
size_t Node::Get_Npar() const {
	return _edgein.size();
};
/*------------------------------------------------------------------*/
size_t Node::Get_Nsons() const {
	return _edgeout.size();
};
/*------------------------------------------------------------------*/
size_t Node::Get_level() const {
	return _level;
};
/*------------------------------------------------------------------*/
size_t Node::Get_Rlevel() const {
	return _Rlevel;
};
/*------------------------------------------------------------------*/
size_t Node::Get_son(size_t i) const {
	return _edgeout[i];
};
/*------------------------------------------------------------------*/
size_t Node::Get_par(size_t i) const {
	return _edgein[i];
};
/*------------------------------------------------------------------*/
