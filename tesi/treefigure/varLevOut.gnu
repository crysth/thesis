
#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
#set output "./VoutVSlev.eps"

#set lmargin 6.5
#set rmargin 1.2
#set size 1,1
#set size ratio 0.7

#set multiplot layout 1,3

set ylabel "Mean outdegree"
set xlabel "Levels"

#set key left
set keytitle "S=2000 N=1000"

#set xtics 4
#set ytics 2 norotate

#p [0:18][0:20] "data/./SRlevelVSoutdegmean.1000102000.dat" u 1:2 w lp lc 2 lw 3 pt 2 ps 1.5 title "k=10", for[i=4:10:2]"data/./SRlevelVSoutdegmean.1000102000.dat" u 1:i w lp lc 2 lw 3 pt i ps 1.5 notitle, "data/./SRlevelVSoutdegmean.1000502000.dat" u 1:2 w lp lc 3 lw 3 pt 2 ps 1.5 title "k=50", for[i=4:10:2]"data/./SRlevelVSoutdegmean.1000502000.dat" u 1:i w lp lc 3 lw 3 pt i ps 1.5 notitle, "data/./SRlevelVSoutdegmean.10001002000.dat" u 1:i w lp lc 5 lw 3 pt 2 ps 1.5 title "k=100", for[i=4:20:2]"data/./SRlevelVSoutdegmean.10001002000.dat" u 1:i w lp lc 5 lw 3 pt i ps 1.5 notitle

p [0:18][0:20] "data/./SRlevelVSoutdegmean.1000102000.dat" u 1:2 w l lc 2 lw 4 title "k=10", for[i=4:10:2]"data/./SRlevelVSoutdegmean.1000102000.dat" u 1:i w l lc 2 lw 4 notitle, "data/./SRlevelVSoutdegmean.1000502000.dat" u 1:2 w l lc 3 lw 4 title "k=50", for[i=4:10:2]"data/./SRlevelVSoutdegmean.1000502000.dat" u 1:i w l lc 3 lw 4 notitle, "data/./SRlevelVSoutdegmean.10001002000.dat" u 1:i w l lc 5 lw 4 title "k=100", for[i=4:20:2]"data/./SRlevelVSoutdegmean.10001002000.dat" u 1:i w l lc 5 lw 4 notitle


