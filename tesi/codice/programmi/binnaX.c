#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
	fstream f;
	double help;
	vector<double> livelli, nodi;

	f.open(argv[1],ios::in);
	f>>help;
	while(!f.eof()){
		livelli.push_back(help);
		f>>help;
		nodi.push_back(help);
		f>>help;
	}

	int bin_in=0,bin_out=atoi(argv[2]),cont=0,nbin=1;
	double mean=0;

	for(size_t i=0;i<livelli.size();i++){
		if(livelli[i]<=bin_out) {
			mean+=nodi[i];
			cont++;
		}
		else {
			nbin++;
			if (cont!=0) mean/=cont;
			cout<<bin_out<<"\t"<<mean<<endl;
			mean=0;
			cont=0;
			bin_in=bin_out;
			bin_out=pow(atoi(argv[2]),nbin);

		}
	}
	if (cont!=0) {
		mean/=double(bin_out-bin_in);
		cout<<bin_out<<"\t"<<mean<<endl;
	}

	return 0;
}
