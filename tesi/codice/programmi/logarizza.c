// Logarizza nomefile binx biny
// Logarizza nomefile 0 0

#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char **argv){

	fstream f;
	double help;
	string xlabel;
	string ylabel;
	vector<double> x,y;

	f.open(argv[1],ios::in);
	f>>xlabel;
	f>>ylabel;
	f>>help;
	while(!f.eof()){
		x.push_back(help);
		f>>help;
		y.push_back(help);
		f>>help;
	}

	cout<<xlabel<<"\t"<<ylabel<<endl;
	for(size_t i=0;i<y.size();i++) cout<<log(x[i])/log(atof(argv[2]))<<"\t"<<log(y[i])/log(atof(argv[3]))<<endl;

	return 0;
}
