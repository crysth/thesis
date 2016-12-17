
unset key
set xlabel "Levels" 
set ylabel "Outdegree mean" 

set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
set output "Coutdeg.yul.eps"


set xtics 10
set ytics 0.5
#set rmargin 0.5
set multiplot layout 1,3

#set lmargin 3.5
vec = "94 122 58"
plot [1:34][] for[i in vec] "./data/RlevVSoutdmean.yul.dat" u 1:int(i) w l lw 1.5

#set lmargin 3.5

unset ylabel

vec = "130 28 32"
plot [1:34][] for[i in vec] "./data/RlevVSoutdmean.yul.dat" u 1:int(i) w l lw 1.5


vec = "140 106 84"
plot [1:34][] for[i in vec] "./data/RlevVSoutdmean.yul.dat" u 1:int(i) w l lw 1.5




#    EOF
