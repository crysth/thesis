/*--------------------------------------------------------------------



	funzioni.cpp

	Implementazione delle funzioni quicksort e runtime.

	swap e' una macro che permette di scambiare 2 size_t.



--------------------------------------------------------------------*/
/*==================================================================*/

#include "funzioni.hpp"

#define swap(a,b) {size_t c=(a); a=(b); b=(c); }


/*--------------------------------------------------------------------
 funzione quicksort
--------------------------------------------------------------------*/

void quicksort(size_t N, size_t v1[], size_t v2[]) {
	size_t i, j, separator;
	if(N<2) return;
	separator = v1[N/2];
	i=0; j=N-1;
	while(j>i) {
		while(v1[i]<separator) i++;
		while(v1[j]>separator) j--;
		if (i<j){
			swap(v1[i], v1[j]);
			swap(v2[i], v2[j]);
			i++;
		}
	}
	quicksort(i,v1,v2);
	quicksort(N-i,v1+i,v2+i);
};


/*---------------------------------------------------------------------
 funzione runtime
---------------------------------------------------------------------*/
double runtime() {
	struct timeval deltatime;
	gettimeofday(&deltatime, NULL);
	return deltatime.tv_sec + deltatime.tv_usec/1000000.0;
}

/*--------------------------------------------------------------------*/
size_t maxvettore(vector<size_t> v) {
	size_t i = 0;
	size_t max = v[0];
	for(i=0; i<v.size(); i++) {
		if(v[i] > max) max=v[i];
//		cout << v[i] << endl;
	}
//	cout << max << endl;
	return max;
}

