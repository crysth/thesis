


unset key
set xlabel "Levels" 
set ylabel "Outdegree mean" 

#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
#set output "Coutdeg.cpp1.eps"


set xtics 2
set ytics 200


set multiplot layout 1,3



vec = "108 114 116 178 124 198 208"
plot [1:10][] for[i in vec] "./data/RlevVSoutdmean.cpp.dat" u 1:int(i) w l lw 1.5 

unset ylabel


vec = "68 102 144 152 180 204 206"
plot [1:11][] for[i in vec] "./data/RlevVSoutdmean.cpp.dat" u 1:int(i) w l lw 1.5

vec = "12 60 110 154 196"
plot [1:12][] for[i in vec] "./data/RlevVSoutdmean.cpp.dat" u 1:int(i) w l lw 1.5



#    EOF
