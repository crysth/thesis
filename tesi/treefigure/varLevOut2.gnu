
set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
set output "./VoutVSlev2.eps"

#set lmargin 6.5
#set rmargin 1.2
#set size 1,1
#set size ratio 0.7

#set multiplot layout 1,3

set ylabel "Mean outdegree"
set xlabel "Levels"

set key left
set keytitle "k=100 N=1000"

#set xtics 4
#set ytics 2 norotate
set key spacing 1.5
set key at 2,12

p [0:14][0:15] "data/./SRlevelVSoutdegmean.10001002500.dat" u 1:2 w lp lc 2 lw 3 pt 2 ps 1.5 title "S=2500", for[i=4:20:2]"data/./SRlevelVSoutdegmean.10001002500.dat" u 1:i w lp lc 2 lw 3 pt i ps 1.5 notitle, "data/./SRlevelVSoutdegmean.10001003500.dat" u 1:2 w lp lc 3 lw 3 pt 2 ps 1.5 title "S=3500", for[i=4:20:2]"data/./SRlevelVSoutdegmean.10001003500.dat" u 1:i w lp lc 3 lw 3 pt i ps 1.5 notitle, "data/./SRlevelVSoutdegmean.10001005000.dat" u 1:i w lp lc 5 lw 3 pt 2 ps 1.5 title "S=5000", for[i=4:20:2]"data/./SRlevelVSoutdegmean.10001005000.dat" u 1:i w lp lc 5 lw 3 pt i ps 1.5 notitle


