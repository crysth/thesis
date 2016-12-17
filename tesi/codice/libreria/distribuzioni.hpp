#ifndef _DISTRIBUZIONI_HPP_
#define _DISTRIBUZIONI_HPP_

#include <fstream>
#include <vector>

#include "packagegraph.hpp"

using namespace std;

class Distribuzioni {

	public:
		//Costruttore/Distruttore
		Distribuzioni();
		Distribuzioni(string path);
		Distribuzioni(string path, string language);
		~Distribuzioni();

		//Funzioni
		void set_path();
		void set_path(string path);

		void outdegrees(Packagegraph *pac);
		void outdegrees(Packagegraph *pac, size_t cut_lev, size_t cut_nodes);
		void indegrees(Packagegraph *pac);

		void leaves(Packagegraph *pac);

		void roots_outdeg(Packagegraph *pac);
		void leaves_indeg(Packagegraph *pac);

		void Nnodes(Packagegraph *pac);
		void depth(Packagegraph *pac);

		void leaves_position(Packagegraph *pac);


		void clear();

	private:
		fstream _f1,_f2,_f3,_f4,_f5,_f6,_f7,_f8, _f11;
		vector<size_t> _outdeg, _indeg, _roots_outdeg, _leaves_indeg;
		bool check, _check1, _check2, _check3, _check4, _check5, _check6, _check7, _check8, _check11;
		string _path;
		string _language;
};

#endif

