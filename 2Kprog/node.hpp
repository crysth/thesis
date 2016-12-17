/*--------------------------------------------------------------------



	node.hpp

	Dichiarazione della classe node.
	La classe node realizza un nodo, rappresentato secondo 
	una lista di edges entranti e una lista di edges uscenti.
	Gli edges sono schematizzati come lista di indici, a
	rappresentare le posizioni dei nodi entranti e uscenti
	definite nel loro grafo di appartenenza. 
	Viene salvato anche il livello del nodo, indispensabile
	per l'algoritmo top-down.




--------------------------------------------------------------------*/
/*==================================================================*/

#ifndef _NODE_HPP_
#define _NODE_HPP_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node {

	public:
		//Costruttore/Distruttore
		Node();
		~Node();

		//Assegnamento
		Node &operator=(Node &obj);

		//Funzioni
		void Add_edge_in(size_t number);
		void Add_edge_out(size_t number);

		//Set
		void Set_level(size_t level);
		void Set_Rlevel(size_t Rlevel);

		//Get
		size_t Get_Npar() const;
		size_t Get_Nsons() const;
		size_t Get_level() const;
		size_t Get_Rlevel() const;

		size_t Get_son(size_t i) const;
		size_t Get_par(size_t i) const;


	private:
		vector<size_t> _edgein;
		vector<size_t> _edgeout;
		size_t _level;
		size_t _Rlevel;

};

#endif

