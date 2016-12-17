#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
#set output "./Mvarleaves.eps"
set lmargin 6.5
set rmargin 1.2
#set size 1,1
#set size ratio 0.7
set multiplot layout 1,2 

f(x)=a*log(x) + b
fit f(x) "data/odepVSlea.leaves.001.dat" via a, b
g(x)=c*log(x) + d
fit g(x) "data/odepVSlea.leaves.15.dat" via c, d
h(x)=e*log(x) + z
fit h(x) "data/odepVSlea.leaves.3.dat" via e, z


p [1:3500][2:13] f(x) w l lw 3 lc 3 notitle, "data/odepVSlea.leaves.001.dat" w p ps 1.5 lc 3 lt 7 title "0.01", g(x) w l lw 3 lc 4 notitle, "data/odepVSlea.leaves.15.dat" w p ps 1.5 pt 7 lc 4 title "0.15", "data/odepVSlea.leaves.3.dat" w p ps 1.5 lc 2 pt 7 title "0.3",h(x) w l lw 3 lc 2 notitle

set logscale x
#set xtics 100
set ylabel "Optimal depth" offset 2
set xlabel "Leaves"
i = 12
p [1:3500][2:13] f(x) w l lw 1 notitle, "data/odepVSlea.leaves.1.dat" w p ps 1.5 lc 3 lt 7 notitle

unset logscale
set ylabel "Outdegree mean" offset 2
set xlabel "Levels"
set keytitle "Leaves"
set xtics 2
set ytics 0.5
set key left
p [1:13][1.5:3] "data/rapp500.dat" w lp lc 2 ps 1.5 lw 1 pt 2 title "500", "data/rapp1000.dat" w lp lc 3 ps 1.5 lw 1 pt 4 title "1000", "data/rapp1500.dat" w lp lc 4 ps 1.5 lw 1 pt 6 title "1500", "data/rapp2000.dat" w lp lc 5 ps 1.5 lw 1 pt 8 title "2000", "data/rapp2500.dat" w lp lc 6 ps 1.5 lw 1 pt 10 title "2500", "data/rapp3000.dat" w lp lc 7 ps 1.5 lw 1 pt 12 title "3000"

unset multiplot
