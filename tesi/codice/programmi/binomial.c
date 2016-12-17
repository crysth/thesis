#include <iostream>
#include <fstream>
#include <cstdlib>

#include <gsl/gsl_randist.h>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {

	fstream f;
	for(size_t i=100;i<350;i++) {
		cout<<i<<"\t"<< (gsl_ran_binomial_pdf(i, 0.0001, floor(300./0.0001)) ) << endl;
	}

	return 0;
}
