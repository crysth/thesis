#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char **argv){

	system(("awk '{print $1,$2}' "+string(argv[1])+" | sort -n > .tempJ").c_str());

	fstream f;
	double help;
	string xlabel;
	string ylabel;
	vector<double> livelli, nodi;

	f.open(".tempJ",ios::in);
	f>>xlabel;
	f>>ylabel;
	f>>help;
	while(!f.eof()){
		livelli.push_back(help);
		f>>help;
		nodi.push_back(help);
		f>>help;
	}

	system("rm .tempJ");

	int bin_out=atoi(argv[2]),cont=0,nbin=1;
	double mean=0;

	cout<<xlabel<<"\t"<<ylabel<<endl;

	for(size_t i=0;i<livelli.size();i++){
		if(livelli[i]<=bin_out) {
			mean+=nodi[i];
			cont++;
		}
		else {
			nbin++;
			if (cont!=0) mean/=cont;
			if(i==livelli.size()-1 && mean==0) break;
			cout<<bin_out<<"\t"<<mean<<endl;
			mean=0;
			cont=0;
			bin_out = pow(atoi(argv[2]),nbin);

		}
	}
	if (cont!=0) {
		mean/=cont;
		cout<<bin_out<<"\t"<<mean<<endl;
	}
	return 0;
}
