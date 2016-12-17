/*--------------------------------------------------------------------



	graph.hpp

	Dichiarazione della classe graph.
	La classe graph permette la gestione di un grafo,
	ovvero di un vettore di nodi.
	La funzione find_levels permette di ottenere il livello di 
	profondita' di ogni nodo (valutato come la distanza massima
	dalla/dalle root).
	La funzione HTD implementa l'algoritmo top-down che permette
	di correggere i dati della matrice in ingresso.



--------------------------------------------------------------------*/
/*==================================================================*/

#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <map>
#include <set>
#include "node.hpp"
#include "funzioni.hpp"

using namespace std;

class Graph {

	public:
		//Costruttori/Distruttore
		Graph();
		Graph(const char *edgefile);
		~Graph();

		//Assegnamento
		Graph &operator=(const Graph &obj);

		//Funzioni
		void HTD(double **scores, string **namescores, size_t nrows);

		//Set
		void set(vector<size_t> from, vector<size_t> to, bool connection = 0);
		void clear();

		//Get
		size_t depth();
		size_t Nnodes();
		size_t Nnodes(size_t level);
		size_t RNnodes(size_t level);
		size_t diamonds();

		size_t Nleaves();

		size_t outdeg(size_t nodo);
		size_t indeg(size_t nodo);

		size_t brothers(size_t level);
		size_t Rbrothers(size_t level);

		vector<size_t> leaves_depth();
		vector<size_t> nodes_depth();

		vector<size_t> indegrees();
		vector<size_t> outdegrees();
		vector<size_t> leaves_indegrees();
		vector<size_t> roots_outdegrees();

		vector<double> mean_Routdegrees();
		vector<double> mean_outdegrees();

		vector<size_t> Kin();
		vector<size_t> Kout();

		//Statistics
		double mean_depth();
		double mean_leaves_depth();
		double mean_Rdepth();
		double mean_outdeg();
		double mean_Routdeg(size_t level);
		double mean_outdeg(size_t level);

		double cost(double lambda);
		double cost(size_t nodo, double lambda);
		double recursive_cost(double lambda);
		double recursive_cost(size_t nodo, double lambda);

//		OVERLOADING DEL <<
		friend ostream &operator<<(ostream &os, Graph &g);

	private:
		Node *_nodes;
		size_t _Nnodes;
		size_t *_ordernodes;
		size_t *_Rordernodes;
		vector<size_t> _leaves;
		vector<size_t> _roots;
		size_t _diamonds;
		bool _diamonds_check;

		vector<size_t> _Kin;
		vector<size_t> _Kout;

		void find_levels();
		void find_reversed_levels();
		void find_leaves();
		void find_roots();
		void visita(size_t node, std::set<size_t> &visitati);
		void find_connection();
		void find_Kin();
		void visita_down(size_t node, std::set<size_t> &visitati);
		void find_Kout();
		void visita_up(size_t node, std::set<size_t> &visitati);
		void find_diamonds();
		void visita_diamond(size_t analyzed, size_t node, std::set<size_t> &visitati, std::set<size_t> &diamanti);
};
#endif

