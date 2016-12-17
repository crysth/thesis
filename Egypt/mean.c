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

	double sum=0;

	for(size_t i=0;i<x.size();i++){
		sum+=x[i]*y[i];
	}
	
	cout<<sum<<endl;

	return 0;
}
