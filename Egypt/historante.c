//non sortali prima di usarlo!

#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char **argv){

system(("sort -n "+string(argv[1])+" > .tempC").c_str());

	fstream f;
	double help;
	vector<double> x;

	f.open(".tempC",ios::in);
	f>>help;
	while(!f.eof()){
		x.push_back(help);
		f>>help;
	}

system("rm .tempC");

	double bin_in=0,bin_out=atof(argv[2]),cont=0,nbin=1;
	double mean=0;

	for(size_t i=0;i<x.size();i++){
		if(x[i]<=bin_out) {
			mean++;
		//	cont++;
		}
		else {
			nbin++;
		//	if (cont!=0) mean/=cont;
			cout<<bin_in+double(bin_out-bin_in)/2.<<"\t"<<mean<<endl;//"\t"<<bin_in<<"\t"<<bin_out<<endl;
			mean=0;
			cont=0;
			bin_in=bin_out;
			bin_out=atof(argv[2])*nbin;

		}
	}
	if (cont!=0) {
		mean/=double(bin_out-bin_in);
		cout<<bin_in+double(bin_out-bin_in)/2.<<"\t"<<mean<<endl;
	}
	return 0;
}
