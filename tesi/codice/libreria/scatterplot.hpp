#ifndef _SCATTERPLOT_HPP_
#define _SCATTERPLOT_HPP_

#include <fstream>
#include <vector>

#include "packagegraph.hpp"

using namespace std;

class Scatterplot {

	public:
		//Costruttore/Distruttore
		Scatterplot();
		Scatterplot(string path);
		Scatterplot(string path, string language);
		~Scatterplot();

		//Funzioni
		void set_path();
		void set_path(string path);
		void set_language(string language);

		void leaves_Nnodes(Packagegraph *pac, size_t minimum);
		void levels_Nnodes(Packagegraph *pac, size_t minimum);
		void Rlevels_Nnodes(Packagegraph *pac, size_t minimum);

		void levels_Nnodes(Packagegraph *pac, size_t minimum, bool level);
		void Rlevels_outdegmean(Packagegraph *pac, size_t minimum, size_t nodimin=0);
		void levels_outdegmean(Packagegraph *pac, size_t minimum);

		void levels_indegrees(Packagegraph *pac);
		void levels_outdegrees(Packagegraph *pac);
		void LeavesIndegrees_LeavesLevels(Packagegraph *pac);
		void depth_Nnodes(Packagegraph *pac);
		void Vnodes_Nnodes(Packagegraph *pac);

		void meanoutdeg_Nnodes_depth(Packagegraph *pac);

		void depth_Nnodes_outdeg(Packagegraph *pac, size_t minN, size_t minL);

		void clear();

	private:
		fstream _f1,_f2,_f3,_f4,_f5,_f6,_f7,_f8,_f9, _f10;
		fstream _ff1,_ff2,_ff3,_ff4,_ff5,_ff6,_ff7;
		vector<size_t> _levels, _outdeg, _indeg, _leaves_indeg, _leaves_levels;
		bool _check, _check1, _check2, _check3, _check4, _check5, _check6,_check7,_check8,_check9, _check10;
		string _path;
		string _language;
};

#endif

