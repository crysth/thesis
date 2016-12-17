
#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
#set output "./VoutVSlev3.eps"

#set lmargin 6.5
#set rmargin 1.2
#set size 1,1
#set size ratio 0.7

#set multiplot layout 1,3

set ylabel "Mean outdegree"
set xlabel "Levels"

#set key left
set keytitle "S=2000 k=100"
set key at 6,25
set key spacing 1.5

#set xtics 4
#set ytics 2 norotate
#set key left

#p [0:18][0:27] "data/00500.dat" every ::1::12 u 1:2 w lp lc 2 lt 2 lw 3 ps 1.5 title "N=500", "data/00500.dat" every ::1::10 u 1:4 w lp lt 4 lc 2 lw 3 ps 1.5 notitle, "data/00500.dat" every ::1::11 u 1:6 w lp lt 6 lc 2 lw 3 ps 1.5 notitle, "data/00500.dat" every ::1::10 u 1:8 w lp lt 8 lc 2 lw 3 ps 1.5 notitle, "data/02000.dat" every ::1::11 u 1:2 w lp lc 3 lt 2 lw 3 ps 1.5 title "N=2000", "data/02000.dat" every ::1::12 u 1:4 w lp lt 4 lc 3 lw 3 ps 1.5 notitle, "data/02000.dat" every ::1::12 u 1:6 w lp lt 6 lc 3 lw 3 ps 1.5 notitle, "data/02000.dat" every ::1::11 u 1:8 w lp lt 8 lc 3 lw 3 ps 1.5 notitle, "data/05000.dat" every ::1::15 u 1:2 w lp lc 5 lt 2 lw 3 ps 1.5 title "N=5000", "data/05000.dat" every ::1::14 u 1:4 w lp lt 4 lc 5 lw 3 ps 1.5 notitle, "data/05000.dat" every ::1::15 u 1:6 w lp lt 6 lc 5 lw 3 ps 1.5 notitle, "data/05000.dat" every ::1::14 u 1:8 w lp lt 8 lc 5 lw 3 ps 1.5 notitle

p [0:18][0:27] "data/00500.dat" every ::1::12 u 1:2 w l lc 2 lt 2 lw 4 title "N=500", "data/00500.dat" every ::1::10 u 1:4 w l lt 4 lc 2 lw 4 notitle, "data/00500.dat" every ::1::11 u 1:6 w l lt 6 lc 2 lw 4 notitle, "data/00500.dat" every ::1::10 u 1:8 w l lt 8 lc 2 lw 4 notitle, "data/02000.dat" every ::1::11 u 1:2 w l lc 3 lt 2 lw 4 title "N=2000", "data/02000.dat" every ::1::12 u 1:4 w l lt 4 lc 3 lw 4 notitle, "data/02000.dat" every ::1::12 u 1:6 w l lt 6 lc 3 lw 4 notitle, "data/02000.dat" every ::1::11 u 1:8 w l lt 8 lc 3 lw 4 notitle, "data/05000.dat" every ::1::15 u 1:2 w l lc 4 lt 2 lw 4 title "N=5000", "data/05000.dat" every ::1::14 u 1:4 w l lt 4 lc 4 lw 4 notitle, "data/05000.dat" every ::1::15 u 1:6 w l lt 6 lc 4 lw 4 notitle, "data/05000.dat" every ::1::14 u 1:8 w l lt 8 lc 4 lw 4 notitle 

