
unset key
set xlabel "Levels" 
set ylabel "Mean outdegree" offset 1

#set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
#set output "Coutdeg.py.eps"


set xtics 2
set ytics 150
set rmargin 1


set multiplot layout 1,3

vec = "758 760 764 766 768"
plot [1:6.5][] for[i in vec] "./data/RlevVSoutdmean.py.dat" u 1:int(i) w l lw 3.5

unset ylabel
set ytics 200

vec = "492 496 504 532 546 "
plot [1:7.5][] for[i in vec] "./data/RlevVSoutdmean.py.dat" u 1:int(i) w l lw 3.5

set ytics 500

vec = "160 188 360 378 380 "
plot [1:8.5][] for[i in vec] "./data/RlevVSoutdmean.py.dat" u 1:int(i) w l lw 3.5




#    EOF
