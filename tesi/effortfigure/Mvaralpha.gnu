#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
#set output "./Mvaralpha.eps"
set lmargin 6.5
set rmargin 1.2
#set size 1,1
#set size ratio 0.7
set multiplot layout 1,2 

f(x)=a*x + b
fit f(x) "data/odepVSlea.1000.alpha.dat" via a, b

set xtics 0.05
set ytics 1
set ylabel "Optimal depth" offset 2
set xlabel "{/Symbol a}"
p [0:0.21][8:12] f(x) w l lw 1 notitle, "data/odepVSlea.1000.alpha.dat" w p ps 1.5 lc 3 lt 7 notitle

set ylabel "Outdegree mean" offset 2
set xlabel "Levels"
set keytitle "{/Symbol a}"
set xtics 2
set ytics 0.5
set key left
p [1:12][1.5:3] "data/rapp005.dat" w lp lc 2 ps 1.5 lw 1 pt 2 title "0.005", "data/rapp055.dat" w lp lc 3 ps 1.5 lw 1 pt 4 title "0.055", "data/rapp105.dat" w lp lc 4 ps 1.5 lw 1 pt 6 title "0.105", "data/rapp155.dat" w lp lc 5 ps 1.5 lw 1 pt 8 title "0.155", "data/rapp205.dat" w lp lc 6 ps 1.5 lw 1 pt 10 title "0.205"

unset multiplot
