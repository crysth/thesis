


set xlabel "Levels" 
set ylabel "Outdegree mean" offset 1.5

set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
set output "Cconfronto.eps"

set key left
set xtics 2
set ytics 50

set key at 2,300

set multiplot layout 1,2
set rmargin 2

set keytitle "C++ data"
vec = "68 102 144 152 206"
plot [1:11][] for[i in vec] "./data/RlevVSoutdmean.cpp.dat" u 1:int(i) w l lw 1.5 notitle

unset ylabel
set ytics 2

set key at 2,12


set keytitle "Simulations"
vec=' 1798 1804 1806 1814 1820 1822 1826 1828 1838 1840 1842 1852 1864'
p [0:14]for[i in vec]"../treefigure/data/01000.dat" u 1:int(i) w l notitle


#    EOF
