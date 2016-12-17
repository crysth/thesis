
set terminal postscript eps enhanced color solid "Helvetica" 14 blacktext
set output "./TEXoutdeg1.eps"

set lmargin 6.5
set rmargin 1.2
set size 1,1
set size ratio 0.7

set boxwidth 1
set ytics 0.01 rotate
set logscale y
set ylabel "Probability" offset 1.5
set xlabel "Outdegree"
set xtics 4

set multiplot layout 1,2 
p [-0.5:16][:1] "data/Noutdegrees.500.dat" lc 3 with boxes title "Initial nodes = 500"
p [-0.5:16][:1] "data/Noutdegrees.1000.dat" lc 3 with boxes title "Initial nodes = 1000"
unset multiplot

set output "./TEXoutdeg2.eps"
set multiplot layout 1,2 
p [-0.5:24][:1] "data/Noutdegrees.2000.dat" lc 3 with boxes title "Initial nodes = 2000"
p [-0.5:24][:1] "data/Noutdegrees.3000.dat" lc 3 with boxes title "Initial nodes = 3000"
unset multiplot

set output "./TEXoutdeg3.eps"
set multiplot layout 1,2 
p [-0.5:28][:1] "data/Noutdegrees.4000.dat" lc 3 with boxes title "Initial nodes = 4000"
p [-0.5:36][:1] "data/Noutdegrees.10000.dat" lc 3 with boxes title "Initial nodes = 10000"
unset multiplot

