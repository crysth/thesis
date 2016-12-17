
set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
set output "./Ttotnodes.eps"

f(x)=a*x + b
fit f(x) "data/rettanodi.dat" u 1:2 via a, b

set lmargin 6.5
set rmargin 1.2
#set size 1,1
#set size ratio 0.7
set multiplot layout 1,2 

set ylabel "Mean total nodes" offset 1.5
set xlabel "Initial nodes"
set xtics 2000
set ytics 500 rotate
p [:][0:1990] f(x) w l lw 1 notitle, "data/rettanodi.dat" w p ps 1.5 lc 3 lt 7 notitle

set ylabel "Probability" offset 2
set xlabel "Total nodes"
set xtics 50
set ytics 0.01 norotate

p [875:1075]"data/NNnodes5000.dat" lc 3 with boxes title "k=100 S=2000 N=5000"

unset multiplot


