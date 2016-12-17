LIB = 
CC = g++ 
OPT = -O3 -Wall -funroll-loops -g -std=c++11
MAIN = main
GSL = -lgsl -lgslcblas

INCS = `root-config --cflags`
LIBS = `root-config --libs`
 
all: binnaX binnaXY fittapowerlaw Phisto Histo Test Splittatore Heatmappa Normalizza Sequenzia Bin Mean

Mean : mean.c
	$(CC) $(OPT) mean.c -o Mean
 
Bin : binomial.c
	$(CC) $(OPT) binomial.c -o Bin $(GSL)
 
Sequenzia : sequenzia.c
	$(CC) $(OPT) sequenzia.c -o Sequenzia
 
Normalizza : normalizza.c
	$(CC) $(OPT) normalizza.c -o Normalizza
 
Heatmappa : heatmap.c
	$(CC) $(OPT) heatmap.c -o Heatmappa
 
Splittatore : splittatore.c
	$(CC) $(OPT) splittatore.c -o Splittatore
 
Test : Test.cpp
	$(CC) $(OPT) Test.cpp -o Test $(GSL)

Phisto : historantep.c
	$(CC) $(OPT) historantep.c -o Phisto

Histo : historante.c
	$(CC) $(OPT) historante.c -o Histo

binnaX : binnaX.c
	$(CC) $(OPT) binnaX.c -o binnaX

binnaXY : binnaXY.c
	$(CC) $(OPT) binnaXY.c -o binnaXY

fittapowerlaw : fittapowerlaw.C
	$(CC) $(OPT) -o fittapowerlaw fittapowerlaw.C $(INCS) $(LIBS)

clean :
	rm -f *.o *.x *~

pure : 
	rm -f *.o *.x *~ ; clear; ls --color; 
