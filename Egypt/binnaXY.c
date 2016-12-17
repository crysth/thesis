//sortali prima di usarlo!

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

//	int bin_in=0;
	int bin_out=atoi(argv[2]),cont=0,nbin=1;
	double mean=0,var=0;

	cout<<xlabel<<"\t"<<ylabel<<endl;

	for(size_t i=0;i<livelli.size();i++){
		if(livelli[i]<=bin_out) {
			mean+=nodi[i];
			var+=nodi[i]*nodi[i];
			cont++;
		}
		else {
			nbin++;
			if (cont!=0) {
				mean/=cont;
				var/=cont;
			}
			if(i==livelli.size()-1 && mean==0) break;
//			cout<<bin_in+double(bin_out-bin_in)/2.<<"\t"<<mean<<endl;//"\t"<<bin_in<<"\t"<<bin_out<<endl;
			cout<<bin_out<<"\t"<<mean<<"\t"<<sqrt(var-(mean*mean))<<"\t"<<sqrt(var-(mean*mean))/sqrt(double(cont))<<endl;// 
			mean=0;
			var=0;
			cont=0;
//			bin_in=bin_out;
//			bin_out+=pow(atoi(argv[2]),nbin);
	//		bin_in = pow(atoi(argv[2]),nbin-1);
			bin_out = pow(atoi(argv[2]),nbin);

		}
	}
	if (cont!=0) {
		mean/=cont;
		cout<<bin_out<<"\t"<<mean<<"\t"<<sqrt(var-(mean*mean))<<"\t"<<sqrt(var-(mean*mean))/sqrt(double(cont))<<endl;//"\t"<<bin_in<<"\t"<<bin_out<<endl;
//		cout<<bin_in+double(bin_out-bin_in)/2.<<"\t"<<mean<<endl;//"\t"<<bin_in<<"\t"<<bin_out<<endl;
	}
	return 0;
}
