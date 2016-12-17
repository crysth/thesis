//non sortali prima di usarlo!

#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

#define enne 10000.

#define Smax 10000

int main(int argc, char **argv){


double sum;

for(size_t s=1; s<Smax;s=s+10){
	for(size_t i=0; i<=s-1;i++){
		sum+=(double(s)/(s-i));
	}
	cout<<s<<"\t";
	for(size_t j=1000; j<enne*10;j=j+1000){
		cout<<sum/j<<"\t";
	}
		cout<<endl;
		sum=0.;
}

	return 0;
}
