set xlabel "Occurrence of the most common symbol"
set grid
set ylabel "Probability"
#set xtics 10
#set ytics 0.02

p "data/campana1000_2000_100.dat" w boxes lw 2 lc 2 title "N=1000 S=2000 k=100", "data/campana500_2000_300.dat" w boxes lw 2 lc 3 title "N=500 S=2000 k=300", "data/campana500_200_50.dat" w boxes lw 2 lc 5 title "N=500 S=200 k=50"

