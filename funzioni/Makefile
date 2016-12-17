LIB = 
CC = g++ 
OPT = -O3 -Wall -funroll-loops -g -std=c++11
MAIN = main
GSL = -lgsl -lgslcblas

INCS = `root-config --cflags`
LIBS = `root-config --libs`
 
all: sigma kappa FdiEsse
 
FdiEsse : FdiEsse.c
	$(CC) $(OPT) FdiEsse.c -o FdiEsse

kappa : kappa.c
	$(CC) $(OPT) -lgsl -lgslcblas kappa.c -o kappa

sigma : sigma.c
	$(CC) $(OPT) sigma.c -o sigma

clean :
	rm -f *.o *.x *~

pure : 
	rm -f *.o *.x *~ ; clear; ls --color; 
