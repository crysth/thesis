
unset key
set xlabel "Levels" 
set ylabel "Mean outdegree" offset 1

#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
#set output "Coutdeg.java.eps"

set xtics 1
set ytics 40

set rmargin 1

set multiplot layout 1,3

vec = "162 102 160 104 106 110 112 32"
plot [1:4.5][] for[i in vec] "./data/RlevVSoutdmean.java.dat" u 1:int(i) w l lw 3.5


unset ylabel
set ytics 100

vec = "14 28 42 166 66 44 196"
plot [1:5.5][] for[i in vec] "./data/RlevVSoutdmean.java.dat" u 1:int(i) w l lw 3.5

set ytics 40

vec = "92 98 108 174 130 192"
plot [1:6.5][] for[i in vec] "./data/RlevVSoutdmean.java.dat" u 1:int(i) w l lw 3.5




#    EOF
