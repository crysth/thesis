#ifndef _LINEPLOT_HPP_
#define _LINEPLOT_HPP_

#include <fstream>
#include <vector>

#include "packagegraph.hpp"

using namespace std;

class Lineplot {

	public:
		//Costruttore/Distruttore
		Lineplot();
		Lineplot(string path);
		Lineplot(string path, string language);
		~Lineplot();

		//Funzioni
		void clear();
		void set_path();
		void set_path(string path);
		void set_language(string language);

		void Rabbit(Packagegraph *pac, size_t limit=0);
		void Pricer(Packagegraph *pac, size_t limit=0);

		void outdegree(Packagegraph *pac, size_t cut_lev, size_t cut_nodes);
		void indegree(Packagegraph *pac, size_t cut_lev, size_t cut_nodes);
		void MeanDepth(Packagegraph *pac);

	private:
		fstream _f1,_f2,_f3,_f4,_f5;
		bool check, mean_check;
		string _path, _language;
};

#endif

