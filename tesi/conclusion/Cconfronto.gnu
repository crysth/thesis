


set xlabel "Levels" 
set ylabel "Outdegree mean"
#offset 1.5

set terminal postscript eps enhanced color solid "Helvetica" 22 blacktext
set output "STsim.eps"

#set key left
#set xtics 2
#set ytics 50

#set key at 2,300

#set multiplot layout 1,2
#set rmargin 2

#set keytitle "C++ data"
#vec = "68 102 144 152 206"
#plot [1:11][] for[i in vec] "./data/RlevVSoutdmean.cpp.dat" u 1:int(i) w l lw 1.5 notitle

#unset ylabel
set ytics 2

set key at 7,10


set keytitle "Sharing Tree\nsimulations"
p [0:17] for[i=2:20:2]"./data/SRlevelVSoutdegmean.10001002000.dat" u 1:i w l notitle


#    EOF
