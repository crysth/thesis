
set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
set output "./Tnodes.eps"

f(x)=a*x + b
fit f(x) "data/rettaleaves.dat" u 1:2 via a, b

set lmargin 6.5
set rmargin 1.2
#set size 1,1
#set size ratio 0.7
set multiplot layout 1,2 

set ylabel "Mean leaves" offset 1.5
set xlabel "Initial nodes"
set xtics 2000
set ytics 100
p [:][:] f(x) w l lw 1 notitle, "data/rettaleaves.dat" w p ps 1.5 lc 3 lt 7 notitle

set ylabel "Probability" offset 2
set xlabel "Leaves"
set xtics 10
set ytics 0.02

p [290:340]"data/simulazioni.dat" lc 3 with boxes title "k=100 S=2000 N=5000", "data/NotBinomial.dat" w lp ps 1.5 title "Analytic solution"

unset multiplot


