#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>

#include <gsl/gsl_cdf.h>
#include <cmath>
#include <sys/time.h>

using namespace std;

int main(int argc, char **argv) {

	system(("awk '{print $2}' "+string(argv[1])+" > .tempT").c_str());

	fstream f;
	double help;
	vector<double> entrate;

	f.open(".tempT",ios::in);
	f>>help;
	while(!f.eof()){
		entrate.push_back(help);
		f>>help;
	}

	system("rm .tempT");

	size_t Ntot=entrate.size();

	size_t Npositivi=0;
	for(size_t i=0;i<Ntot;i++) if (entrate[i]>0.5) Npositivi++;
	cout<<scientific;
	cout<<"Positivi "<<Npositivi<<"\tTotali "<<Ntot<<endl;
	cout<<gsl_cdf_binomial_Q (Npositivi, .5, Ntot)<<"\n";

	return 0;
}
