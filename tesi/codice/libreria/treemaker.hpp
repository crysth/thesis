#ifndef _TREEMAKER_HPP_
#define _TREEMAKER_HPP_

#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_set>
#include "graph.hpp"
#include <gsl/gsl_randist.h>
#include <sys/time.h>

using namespace std;

class TreeMaker {

	public:
		//Costruttore/Distruttore
		TreeMaker();
		~TreeMaker();

		//Funzioni a Steps
		Graph *YuleTree_Time(size_t Nsteps, double outdeg_mean);
		Graph *RussianTree_Time(size_t NrootsInit, size_t Nsteps, double indeg_mean);
		Graph *ReversedRussianTree_Time(size_t NleavesInit, size_t Nsteps, double outdeg_mean);

		void YuleTree_Time(size_t Nsteps, double outdeg_mean, vector<size_t> &from, vector<size_t> &to);
		void RussianTree_Time(size_t NrootsInit, size_t Nsteps, double indeg_mean, vector<size_t> &from, vector<size_t> &to);
		void ReversedRussianTree_Time(size_t NleavesInit, size_t Nsteps, double outdeg_mean, vector<size_t> &from, vector<size_t> &to);

		//Funzioni a Nnodes
		Graph *YuleTree_Nodes(size_t Nnodes, double outdeg_mean);
		Graph *RussianTree_Nodes(size_t NrootsInit, size_t Nnodes, double indeg_mean);
		Graph *ReversedRussianTree_Nodes(size_t NleavesInit, size_t Nnodes, double outdeg_mean);

		void YuleTree_Nodes(size_t Nodes, double outdeg_mean, vector<size_t> &from, vector<size_t> &to);
		void RussianTree_Nodes(size_t NrootsInit, size_t Nnodes, double indeg_mean, vector<size_t> &from, vector<size_t> &to);
		void ReversedRussianTree_Nodes(size_t NleavesInit, size_t Nnodes, double outdeg_mean, vector<size_t> &from, vector<size_t> &to);

		//MC
		Graph *MCTree(size_t NleavesInit, size_t Nsequence, size_t Nsymbols);
		void MCTree(size_t NleavesInit, size_t Nsequence, size_t Nsymbols, vector<size_t> &from, vector<size_t> &to);


	private:
		gsl_rng *r;
		vector<size_t> _from, _to;
		bool **_presenza;
		size_t _NleavesInit;
		size_t _Nnodes;
		size_t _Nsequence;
		size_t _Nsymbols;

		void Simboloricorrente(vector<size_t> &supporto, vector<vector<size_t>> &splittati);
		void Ricorrente(vector<vector<size_t>> split1, size_t &esclude, size_t &esclude2, size_t nextnode, size_t &newnode, size_t &foglie);
		size_t RandomSymbol();



};

#endif

