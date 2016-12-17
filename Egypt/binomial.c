/*--------------------------------------------------------------------



--------------------------------------------------------------------*/
/*==================================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>

#include <gsl/gsl_randist.h>
#include <cmath>

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

	fstream f;
	for(size_t i=100;i<350;i++) {
		cout<<i<<"\t"<< (gsl_ran_binomial_pdf(i, 0.0001, floor(300./0.0001)) ) << endl;
	}



	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

