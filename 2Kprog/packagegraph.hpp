/*--------------------------------------------------------------------




--------------------------------------------------------------------*/
/*==================================================================*/

#ifndef _PACKAGEGRAPH_HPP_
#define _PACKAGEGRAPH_HPP_

#include <string>
#include <vector>
#include <fstream>
#include "node.hpp"
#include "graph.hpp"
#include "funzioni.hpp"

using namespace std;

class Packagegraph {

	public:
		//Costruttori/Distruttore
		Packagegraph();
		Packagegraph(const char *edgefile);
		~Packagegraph();

		//Assegnamento
		Packagegraph &operator=(Packagegraph &obj);

		//Setting
		void add(Graph *g);
		void clear();

		//Get
		string name();
		size_t N();
		size_t depth(size_t i);
		size_t Nnodes(size_t i);
		size_t outdeg(size_t grafo,size_t nodo);
		size_t indeg(size_t grafo,size_t nodo);
		size_t Nleaves(size_t grafo);

		//Set
		void set_name(string name);

		//Quantities
		size_t max_depth();
		size_t Nnodes(size_t i, size_t level);
		size_t RNnodes(size_t i, size_t level);

		//Order Parameters
		size_t diamanti();
		size_t diamanti(size_t i);
		double cost(size_t grafo, double lambda);
		double recursive_cost(size_t grafo, double lambda);

		//Means
		double mean_Nnodes();
		double mean_depth();
		double mean_Rdepth();
		double mean_leaves_depth();
		double mean_leaves_depth(size_t i);
		double mean_outdeg(size_t grafo);

		double mean_meandepth();
		double mean_depth(size_t i);
		double mean_meanRdepth();

		vector<size_t> brothers(size_t graph);

		vector<size_t> Rbrothers(size_t graph);

		//Distributions
		vector<size_t> indegrees();
		vector<size_t> outdegrees();
		vector<size_t> nodes_depth();

		vector<size_t> indegrees(size_t i);
		vector<size_t> outdegrees(size_t i);
		vector<size_t> nodes_depth(size_t i);

		vector<double> mean_Routdegrees(size_t grafo);
		vector<double> mean_outdegrees(size_t grafo);

		vector<size_t> roots_outdegrees();
		vector<size_t> roots_outdegrees(size_t i);

		vector<size_t> leaves_indegrees();
		vector<size_t> leaves_depth();

		vector<size_t> leaves_indegrees(size_t i);
		vector<size_t> leaves_depth(size_t i);

	private:
		vector<Graph*> _grafi;
		size_t _Ngrafi;
		string _nome;
};

#endif

