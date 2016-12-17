
unset key
set xlabel "Levels" 
set ylabel "Outdegree mean" 

set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
set output "Coutdeg.rus.eps"


set xtics 4
set ytics 2


set multiplot layout 1,3

vec = "100 102 104 106 108 114 118"
plot [1:15][] for[i in vec] "./data/RlevVSoutdmean.rus.dat" u 1:int(i) w l lw 1.5

unset ylabel

vec = "42 44 50 52 56"
plot [1:16][] for[i in vec] "./data/RlevVSoutdmean.rus.dat" u 1:int(i) w l lw 1.5


vec = "18 20 36 54 58"
plot [1:17][] for[i in vec] "./data/RlevVSoutdmean.rus.dat" u 1:int(i) w l lw 1.5




#    EOF
