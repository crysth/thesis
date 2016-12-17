
set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
set output "./Toutdeg.eps"

#f(x)=a*log(x) + b
#fit f(x) "data/logoutdegree.dat" u 1:2 via a, b

set lmargin 6.5
set rmargin 1.2
#set size 1,1
#set size ratio 0.7
set multiplot layout 1,2 

set ylabel "Mean outdegree" offset 2.3
set xlabel "Initial nodes"
#set logscale x
set xtics 2000
set ytics 0.01
p [:][0.97:1.02] 1 notitle lc 9, "data/logoutdegree.dat" w p ps 1.5 lc 3 lt 7 notitle

unset logscale
set ylabel "Probability" offset 1.5
set xlabel "Outdegree"
set logscale y
set xtics 4
set ytics rotate
set boxwidth 1

p [-0.5:28][0.00001:1] "data/Noutdegrees.5000.dat" lc 3 with boxes title "k=100 S=2000 N=5000"


unset multiplot


