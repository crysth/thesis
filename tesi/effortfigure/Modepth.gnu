#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
#set output "./Mdepth.eps"
set lmargin 6.5
set rmargin 1.2
#set size 1,1
#set size ratio 0.7
set multiplot layout 1,2 

set logscale y 10

set format y "10^{%L}"
set xtics 2
set ylabel "Number of nodes" offset 0.3
set xlabel "Levels"
set keytitle "Depth"
i = 12
p [1:13][:] for[i=8:11:1]"data/popVSlev.1000.1.depth.dat" u 1:i w lp lc i-6 ps 1.5 pt (i-6)*2 title sprintf("%d",i+1)


unset logscale
set format y
set ylabel "Outdegree mean m(l)" offset 1.1
set xlabel "Levels"
set xtics 2
set ytics 1
i = 11
p [1:12][1:] for[i=8:11:1]"data/outdegVSlev.1000.1.depth.dat" u 1:i w lp lc i-6 ps 1.5 pt (i-6)*2 title sprintf("%d",i+1)

unset multiplot
