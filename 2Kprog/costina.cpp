/*--------------------------------------------------------------------

costina language depth_min `ls`

--------------------------------------------------------------------*/
/*==================================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "libreria.hpp"

using namespace std;

int main(int argc, char **argv) {

	string path="../outputC/";
	string language=argv[1];
	size_t depth_min=atoi(argv[2]);

	Packagegraph *pac;
	Lineplot liner(path, language);

	for(int j=3; j<argc; j++) {
		cerr<<argv[j]<<endl;
		pac = new Packagegraph(argv[j]);
		liner.Pricer(pac, depth_min);
		delete pac;
	}
	return 0;
}
