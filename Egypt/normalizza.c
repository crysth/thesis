//non sortali prima di usarlo!

#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char **argv){

	fstream f;
	double help;
	vector<double> x,y;

	f.open(argv[1],ios::in);
	f>>help;
	while(!f.eof()){
		x.push_back(help);
		f>>help;
		y.push_back(help);
		f>>help;
	}

	double cont=0;

	for(size_t i=0;i<y.size();i++) cont+=y[i];

	for(size_t i=0;i<y.size();i++) cout<<x[i]<<"\t"<<(y[i]/cont)<<endl;

	return 0;
}
