LIB = node.o graph.o funzioni.o packagegraph.o distribuzioni.o scatterplot.o treemaker.o lineplot.o
CC = g++ 
OPT = -O3 -Wall -funroll-loops -g -std=c++11
MAIN = main
GSL = -lgsl -lgslcblas

all : tarantola rabbit costina simulante ldeltal Sbilanciamento trovaPacchetti Simlanciamento Phivalue MRmodel MRvalue

MRvalue : ${LIB} mrvalue.cpp
	${CC} ${OPT} ${LIB} mrvalue.cpp -o MRvalue $(GSL)

MRmodel : ${LIB} mrmodel.cpp
	${CC} ${OPT} ${LIB} mrmodel.cpp -o MRmodel $(GSL)

trovaPacchetti : ${LIB} trovaPacchetti.cpp
	${CC} ${OPT} ${LIB} trovaPacchetti.cpp -o trovaPacchetti $(GSL)

Sbilanciamento : ${LIB} sbilanciamento.cpp
	${CC} ${OPT} ${LIB} sbilanciamento.cpp -o Sbilanciamento $(GSL)

Phivalue : ${LIB} phivalue.cpp
	${CC} ${OPT} ${LIB} phivalue.cpp -o Phivalue $(GSL)

Simlanciamento : ${LIB} simlanciamento.cpp
	${CC} ${OPT} ${LIB} simlanciamento.cpp -o Simlanciamento $(GSL)

ldeltal : ${LIB} ldeltal.cpp
	${CC} ${OPT} ${LIB} ldeltal.cpp -o ldeltal $(GSL)

simulante : ${LIB} simulante.cpp
	${CC} ${OPT} ${LIB} simulante.cpp -o simulante $(GSL)

costina : ${LIB} costina.cpp
	${CC} ${OPT} ${LIB} costina.cpp -o costina $(GSL)

tarantola : ${LIB} tarantola.cpp
	${CC} ${OPT} ${LIB} tarantola.cpp -o tarantola $(GSL)

rabbit : ${LIB} rabbit.cpp
	${CC} ${OPT} ${LIB} rabbit.cpp -o rabbit $(GSL)

main : ${LIB} main.cpp
	${CC} ${OPT} ${LIB} main.cpp -o main $(GSL)

lineplot.o : lineplot.cpp lineplot.hpp
	${CC} ${OPT} -c lineplot.cpp

treemaker.o : treemaker.cpp treemaker.hpp
	${CC} ${OPT} -c treemaker.cpp $(GSL)

node.o : node.cpp node.hpp
	${CC} ${OPT} -c node.cpp

graph.o : graph.cpp graph.hpp
	${CC} ${OPT} -c graph.cpp

packagegraph.o : packagegraph.cpp packagegraph.hpp
	${CC} ${OPT} -c packagegraph.cpp

distribuzioni.o : distribuzioni.cpp distribuzioni.hpp
	${CC} ${OPT} -c distribuzioni.cpp

scatterplot.o : scatterplot.cpp scatterplot.hpp
	${CC} ${OPT} -c scatterplot.cpp

funzioni.o : funzioni.cpp funzioni.hpp
	${CC} ${OPT} -c funzioni.cpp

clean :
	rm -f *.o *.x *~

pure : 
	rm -f *.o *.x *~ ; clear; ls --color; 
