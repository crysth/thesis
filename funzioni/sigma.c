//non sortali prima di usarlo!

#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

#define enne 10000.
#define kappa 60.

#define esse 6.

int main(int argc, char **argv){


double exsigma=enne,cont=1.,sigma;

while( exsigma >0 and (esse+1-cont)>0 and (kappa+1-cont)>0){
//	cout<<cont<<"\t"<<exsigma<<"\t"<<esse+1-cont<<"\t"<<kappa+1-cont<<"\t"<<(1.-pow((1.-1./(esse+1.-cont)),(kappa+1.-cont)))<<endl;

	sigma=floor(  (exsigma +1) * (1.-pow((1.-1./(esse+1.-cont)),(kappa+1.-cont)))  );
	cout<<cont<<"\t"<<sigma<<endl;
	exsigma=sigma;
	cont++;

}
	return 0;
}
