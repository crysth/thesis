compila : rel.tex
	latex rel.tex && bibtex rel && latex rel.tex && latex rel.tex && dvipdf rel.dvi; make clean;

clean :
	rm -rf *~ frontespizio.aux rel.dvi rel.out rel.aux rel.toc rel.log
