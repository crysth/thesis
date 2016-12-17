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
//cout<<argv[1]<<endl;
	f.open(argv[1],ios::in);
        f>>help;
//cout<<help<<endl;
        while(!f.eof()){
                x.push_back(help);
                f>>help;
                y.push_back(help);
                f>>help;
        }

size_t cont=0, cont2=0,max=0;

//vector<vector<double>> matricex, matricey;
vector<vector<double>> matricey;

vector<double> add;
//matricex.push_back(add);
matricey.push_back(add);

//matricex[0].push_back(x[0]);
matricey[0].push_back(y[0]);


for(size_t i=1;i<y.size();i++){
	if(x[i]<x[i-1]){
		cont++;
		matricey.push_back(add);
		if(cont2>max) max=cont2;
		cont2=0;
	}
	matricey[cont].push_back(y[i]);
	cont2++;
}

for(size_t i=0;i<=max;i++){
	cout<<i+1<<"\t";
	for(size_t j=0;j<matricey.size();j++){
		if(matricey[j].size()>i) cout<<matricey[j][i]<<"\t";
		else cout<<"NaN\t";
	}
	cout<<endl;
}



	return 0;
}






