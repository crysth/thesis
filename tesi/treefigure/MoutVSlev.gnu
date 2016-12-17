
set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext
set output "./ToutVSlev.eps"

#set lmargin 6.5
#set rmargin 1.2
set size 1,1
#set size ratio 0.7
set multiplot layout 1,3

set ylabel "Mean outdegree" offset 1.5
set xlabel "Levels"

set key left

set xtics 4
set ytics 2 norotate

vec=' 1782 1838 1840 1842 1846 1854 1860 1880 1886 1896 1902 1910 1922'
set keytitle "Initial\nnodes\n500"
p [0:13][0:14]for[i in vec]"data/00500.dat" every ::1::10 u 1:int(i) w l notitle

vec=' 1798 1804 1806 1814 1820 1822 1826 1828 1838 1840 1842 1852 1864'
set keytitle "Initial\nnodes\n1000"
p [0:14][0:14]for[i in vec]"data/01000.dat" every ::1::11 u 1:int(i) w l notitle

vec=' 136 138 182 184 190 232 246 284 298 316 340 346 366 380 392 424'
set keytitle "Initial\nnodes\n5000"
set ytics 4
p [0:16][0:28]for[i in vec]"data/05000.dat" every ::1::12 u 1:int(i) w l notitle

unset multiplot


