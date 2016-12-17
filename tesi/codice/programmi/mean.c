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

	for(size_t k=1; k<argc; k++){
		f.open(argv[k],ios::in);
		f>>help;
		while(!f.eof()){
			x.push_back(help);
			f>>help;
			y.push_back(help);
			f>>help;
		}
		f.close();
		double sum=0;
	
		for(size_t i=0;i<x.size();i++){
			sum+=x[i]*y[i];
		}
		cout<<sum<<endl;
		x.clear();
		y.clear();
	}
	return 0;
}
