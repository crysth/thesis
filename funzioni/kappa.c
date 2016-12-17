/*--------------------------------------------------------------------



--------------------------------------------------------------------*/
/*==================================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>

#include <gsl/gsl_randist.h>
#include <cmath>
#include <sys/time.h>

using namespace std;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	DEFINE
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define NNODI 1000
#define NSYMBOLS 600
#define NSEQ 60

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	FUNZIONI
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
size_t RandomSymbol(size_t Nsymbol, gsl_rng *r){
	return floor(gsl_ran_flat (r, 1.0, Nsymbol+1));
};
/*--------------------------------*/
/*--------------------------------*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	MAIN
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int main(int argc, char **argv) {
	// GSL //
	gsl_rng *r;
//	r = gsl_rng_alloc (gsl_rng_default);
	r = gsl_rng_alloc (gsl_rng_taus);
	struct timeval deltatime;
	gettimeofday(&deltatime, NULL);
	gsl_rng_set(r,deltatime.tv_usec);
	// VARIABILI //
	unordered_set<size_t> nodi[NNODI];

	// GENERO I NODI //
	for(size_t i=0; i<NNODI; i++){
		for(size_t j=0; j<(gsl_ran_flat(r, 1.0, NSEQ+1)); j++){
//		for(size_t j=0; j<NSEQ; j++){
			nodi[i].insert(RandomSymbol(NSYMBOLS,r));
		}
	}//*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	for(size_t i=0; i<NNODI; i++){
//		for(size_t j=0; j<(gsl_ran_flat(r, 1.0, NSEQ+1)); j++){
		cout<<nodi[i].size()<<endl;
	}//*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//nodi fissati o no?

	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			END
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/





