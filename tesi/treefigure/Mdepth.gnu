
#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
#set output "./Tdepth.eps"

f(x)=a*log(x) + b
fit f(x) "data/logdepth.dat" u 1:2 via a, b

set lmargin 6.5
set rmargin 1.2
#set size 1,1
#set size ratio 0.7
set multiplot layout 1,2 

set ylabel "Mean depth" offset 1.5
set xlabel "Initial nodes"
set logscale x
#set xtics 2000
set ytics 2
p [:][:] f(x) w l lw 1 notitle, "data/logdepth.dat" w p ps 1.5 lc 3 lt 7 notitle

unset logscale
set ylabel "Probability" offset 2
set xlabel "Depth"
set xtics 5
set ytics 0.1

p [:][:] "data/Ndepth.5000.dat" lc 3 with boxes title "k=100 S=2000 N=5000"


unset multiplot


