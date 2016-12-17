/*--------------------------------------------------------------------



--------------------------------------------------------------------*/
/*==================================================================*/

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

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	DEFINE
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	FUNZIONI
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*20.31 The Binomial Distribution

Function: unsigned int gsl_ran_binomial (const gsl_rng * r, double p, unsigned int n)

    This function returns a random integer from the binomial distribution, the number of successes in n independent trials with probability p. The probability distribution for binomial variates is,

    p(k) = {n! \over k! (n-k)! } p^k (1-p)^{n-k}

    for 0 <= k <= n. 

Function: double gsl_ran_binomial_pdf (unsigned int k, double p, unsigned int n)

    This function computes the probability p(k) of obtaining k from a binomial distribution with parameters p and n, using the formula given above. 


Function: double gsl_cdf_binomial_P (unsigned int k, double p, unsigned int n)
Function: double gsl_cdf_binomial_Q (unsigned int k, double p, unsigned int n)

    These functions compute the cumulative distribution functions P(k), Q(k) for the binomial distribution with parameters p and n. 
*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	MAIN
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int main(int argc, char **argv) {
	// GSL //


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
// cout.precision(10);
cout<<"Positivi "<<Npositivi<<"\tTotali "<<Ntot<<endl;
cout<<gsl_cdf_binomial_Q (Npositivi, .5, Ntot)<<"\n";



	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

