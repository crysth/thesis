
// Heatmappa SdepthVSNnodes.cpp.dat 2 2

#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char **argv){

	bool chk=system(("sed '1d' "+string(argv[1])+" | awk '{print $1,$2}' | sort -n > .tempH").c_str());

	chk=system("wc -l .tempH > .conta");

	size_t Ndati;
	fstream f;
	f.open(".conta",ios::in);
	f>>Ndati;
	f.close();
	chk=system("rm .conta");

	double *x = new double[Ndati];
	double *y = new double[Ndati];

	f.open(".tempH",ios::in);

	for(size_t i=0; i<Ndati;i++){
		f>>x[i];
		f>>y[i];
	}

	chk=system("rm .tempH");

	vector<vector<size_t>> matrice;
	vector<size_t> addx;
	addx.clear();
	size_t addy=0;
	matrice.push_back(addx);
	matrice[0].push_back(addy);

	double binx_out=atof(argv[2]);
	double biny_out=atof(argv[3]);

	size_t nbin=0;
	chk=1;
	size_t p=0;

	for(size_t i=0;i<Ndati;i++){
//cout<<"x[i] "<<x[i]<<" y[i] "<<y[i]<<endl;
qui:		if(x[i]<=binx_out) {
//cout<<binx_out<<endl;
			while(chk){
//cout<<"\t"<<pow(biny_out,(p+1))<<endl;
//				if(y[i]<=biny_out*(p+1)){
				if(y[i]<=(biny_out*(p+1))){
					matrice[nbin][p]++;
					chk=0;
				}
				else {
					p++;
					if(matrice[nbin].size()<p+1) matrice[nbin].push_back(0);
//cout<<"\tmatrice incremento y "<<nbin<<" "<<matrice[nbin].size()<<endl;
				}
			}
			chk=1;
			p=0;
		}

		else {
			nbin++;
//			binx_out=atof(argv[2])*(nbin+1);
			binx_out=pow(atof(argv[2]),(nbin+1));
			matrice.push_back(addx);
//cout<<"matrice incremento x "<<matrice.size()<<endl;
			matrice[nbin].push_back(0);
//cout<<"\tmatrice incremento y "<<nbin<<" "<<matrice[nbin].size()<<endl;
//			cout<<"goto"<<endl;
			goto qui;
		}
	}
delete x;
delete y;
//trova la size max
size_t Max=0;
	for(size_t i=0;i<matrice.size();i++){
		if(matrice[i].size()> Max) Max=matrice[i].size();
	}
//cout<<Max<<endl;


/*	for(size_t j=Max;j>0;j--){
//cout<<j<<endl;
		for(size_t i=0;i<matrice.size();i++){
//cout<<"size "<<matrice[i-1].size()<<endl;
			if(matrice[i].size()>j-1) cout<<matrice[i][j-1]<<"\t"; 
			else cout<<0<<"\t";
		}
		cout<<endl;
	}//*/

//for(size_t i=0;i<matrice.size()+1;i++) cout<<0<<"\t";
//cout<<endl;
	for(size_t i=0;i<matrice.size();i++) cout<<0<<"\t"; cout<<endl;

	for(size_t j=0;j<Max;j++){
//		cout<<0<<"\t";
		for(size_t i=0;i<matrice.size();i++){
			if(matrice[i].size()>j) cout<<matrice[i][j]<<"\t"; 
			else cout<<0<<"\t"; 
		}
		cout<<endl;
	}//*/
	return 0;
}
