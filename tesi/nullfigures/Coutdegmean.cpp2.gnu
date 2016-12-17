


unset key
set xlabel "Levels" 
set ylabel "Mean outdegree" offset 2

#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
#set output "Coutdeg.cpp2.eps"

set xtics 2
set ytics 150

set rmargin 1

set multiplot layout 1,3

vec = "52 54 56 58 130 164 172 "
plot [1:7][:850] for[i in vec] "./data/RlevVSoutdmean.cpp.dat" u 1:int(i) w l lw 3.5

unset ylabel
set ytics 100

vec = "18 38 70 78 120 134 "
plot [1:8][] for[i in vec] "./data/RlevVSoutdmean.cpp.dat" u 1:int(i) w l lw 3.5

set ytics 200

vec = "26 32 40 42 50 200 190"
plot [1:9][] for[i in vec] "./data/RlevVSoutdmean.cpp.dat" u 1:int(i) w l lw 3.5




#    EOF
