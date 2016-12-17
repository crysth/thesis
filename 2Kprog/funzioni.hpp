/*--------------------------------------------------------------------



	funzioni.hpp


	Definizione di alcune funzioni che vengono utilizzate 
	all'interno del programma.

	- quicksort permette di ordinare un vettore di size_t
	  accoppiato a un altro vettore, mantenendo la relazione
	  di coppia invariata.

	- runtime restituisce il tempo di running del
	  programma in secondi, con precisione del microsecondo

	- show_time e' una macro che stampa a video l'intervallo
	  di tempo speso da ogni sezione del programma


--------------------------------------------------------------------*/
/*==================================================================*/

#ifndef _FUNZIONI_HPP_
#define _FUNZIONI_HPP_

#include <iostream>
#include <vector>
#include <sys/time.h>
using namespace std;

#define _max(a,b) ((a)>(b)?(a):(b))

/*--------------------------------------------------------------------
 funzione quicksort
--------------------------------------------------------------------*/
void quicksort(size_t N, size_t v1[], size_t v2[]);

/*--------------------------------------------------------------------
 funzione runtime
--------------------------------------------------------------------*/
double runtime();

/*--------------------------------------------------------------------
 macro show_time
--------------------------------------------------------------------*/
#define show_time(t, Dt) t = runtime() - t; cerr<<"-> time "<<t<<" s\n\n"; Dt+=t

/*--------------------------------------------------------------------
 massimo di un vector
--------------------------------------------------------------------*/
size_t maxvettore(vector<size_t>);


#endif
