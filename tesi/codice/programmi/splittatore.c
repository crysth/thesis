#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;


int main(int argc, char **argv){

	fstream f;
	string cest;
	double help;
	vector<double> x,y,z;
	f.open(argv[1],ios::in);
	f>>cest;f>>cest;
        f>>help;
        while(!f.eof()){
                x.push_back(help);
                f>>help;
                y.push_back(help);
                f>>help;
                z.push_back(help);
                f>>help;
        }

	size_t cont=0, cont2=0,max=0;
	vector<vector<double>> matricey, matricez;

	vector<double> add;
	matricey.push_back(add);
	matricez.push_back(add);
	matricey[0].push_back(y[0]);
	matricez[0].push_back(z[0]);

	for(size_t i=1;i<y.size();i++){
		if(x[i]<x[i-1]){
			cont++;
			matricey.push_back(add);
			matricez.push_back(add);
			if(cont2>max) max=cont2;
			cont2=0;
		}
		matricey[cont].push_back(y[i]);
		matricez[cont].push_back(z[i]);
		cont2++;
	}

	for(int i=0;i<=max;i++){
		cout<<i+1<<"\t";
		for(size_t j=0;j<matricey.size();j++){
			if(matricey[j].size()>i && matricez[j][i]>0 && matricey[j].size()!=i+1) cout<<matricey[j][i]<<"\t"<<matricez[j][i]<<"\t";
			else cout<<"NaN\tNaN\t";
		}
		cout<<endl;
	}

	return 0;
}






