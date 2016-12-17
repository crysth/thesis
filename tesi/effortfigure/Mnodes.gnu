
#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
#set output "./Mnodes.eps"

f(x)=a*x + b
fit f(x) "data/leavesVSnodes.dat" u 2:1 via a, b

set lmargin 6.5
set rmargin 1.2
set xtics 1000
set ytics 1000 rotate
#set size 1,1
#set size ratio 0.7
set multiplot layout 1,2 
set ylabel "Leaves" offset 1.1
set xlabel "Total nodes of the tree"
unset key
p [1:6500][1:3500] f(x) w l lw 1 notitle, "data/leavesVSnodes.dat" u 2:1 w p ps 1.5 lc 3 lt 7 notitle

set logscale y 10
set format y "10^{%L}"
set ylabel "Nodes per level" offset 0.3
set xlabel "Levels"
set key
set keytitle "Leaves"
set xtics 2
set ytics auto norotate
p  [1:]"data/nodes500.dat" w lp lc 2 ps 1.5 lw 1 pt 2 title "500", "data/nodes1000.dat" w lp lc 3 ps 1.5 lw 1 pt 4 title "1000","data/nodes1500.dat" w lp lc 4 ps 1.5 lw 1 pt 6 title "1500","data/nodes2000.dat" w lp lc 5 ps 1.5 lw 1 pt 8 title "2000","data/nodes2500.dat" w lp lc 6 ps 1.5 lw 1 pt 10 title "2500","data/nodes3000.dat" w lp lc 7 ps 1.5 lw 1 pt 12 title "3000"
unset multiplot


