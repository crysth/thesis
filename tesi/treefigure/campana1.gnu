set grid
set xlabel "Occurrence of the most common symbol"
set ylabel "Probability"
set xtics 10
#set ytics 100
p [280:340]"data/NotBinomial.dat" w boxes lw 2 lc 4 title "N=5000 S=2000 k=100"

