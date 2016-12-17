set border 31 front linetype -1 linewidth 1.000
set boxwidth
set style fill  empty border
set format x "% g"
set format y "% g"
set format cb "10^{%L}"

unset key
set style increment default
unset style line
unset style arrow
set style histogram clustered gap 2 title  offset character 0, 0, 0

set logscale cb 10

set view map

set surface
unset contour
set clabel '%8.3g'

set mapping cartesian
set datafile separator whitespace
unset hidden3d
set cntrparam order 4
set cntrparam linear
set cntrparam levels auto 5
set cntrparam points 5
set size ratio 0 1,1
set origin 0,0
set style data points
set style function lines
set xzeroaxis linetype -2 linewidth 1.000
set yzeroaxis linetype -2 linewidth 1.000
set zzeroaxis linetype -2 linewidth 1.000
set x2zeroaxis linetype -2 linewidth 1.000
set y2zeroaxis linetype -2 linewidth 1.000
set ticslevel 0.5
set mxtics default
set mytics default
set mztics default
set mx2tics default
set my2tics default
set mcbtics default

set xtics border out scale 1.5,0.75 nomirror norotate  offset character 0, 0, 0 autojustify
set xtics 100000 norangelimit
set xtics add  ("1" 1.0000, "10" 24.1589, "100" 48.3177, "1000" 72.4766, "10000" 96.6354, "100000" 120.794)
set ytics border out scale 1.5,0.75 nomirror norotate  offset character 0, 0, 0 autojustify
set ytics 2 norangelimit
#set ytics add  ("1" 1.00000, "10" 24.1589, "100" 48.3177)


set ztics border in scale 1,0.5 nomirror norotate  offset character 0, 0, 0 autojustify
set ztics autofreq  norangelimit
set nox2tics
set noy2tics
set cbtics border in scale 1,0.5 mirror norotate  offset character 0, 0, 0 autojustify
set cbtics autofreq  norangelimit
set rtics axis in scale 1,0.5 nomirror norotate  offset character 0, 0, 0 autojustify
set rtics autofreq  norangelimit

set xlabel "Number of nodes" 
set xlabel  offset character 0, 0, 0 font "" textcolor lt -1 norotate

set xrange [ 1.00000 : 98.3000 ] noreverse nowriteback

set ylabel "Depth of graphs" offset 2
#set ylabel  offset character 0, 0, 0 font "" textcolor lt -1 rotate by -270

set yrange [ 1.00000 : 10.0000 ] noreverse nowriteback

set cblabel "Number of graphs" 
set cblabel  offset character 1.5, 0, 0 font "" textcolor lt -1 rotate by -270
set cbrange [ * : * ] noreverse nowriteback

set zero 1e-08

set lmargin  -1
set bmargin  -1
set rmargin  -1
set tmargin  -1

set locale "it_IT.UTF-8"

set pm3d explicit at s
set pm3d scansautomatic

set pm3d interpolate 1,1 flush begin noftriangles nohidden3d corners2color mean

set palette positive nops_allcF maxcolors 0 gamma 1.5 color model RGB 
set palette rgbformulae 7, 5, 15

set colorbox default
set colorbox vertical origin screen 0.9, 0.2, 0 size screen 0.05, 0.6, 0 front bdefault
set style boxplot candles range  1.50 outliers pt 7 separation 1 labels auto unsorted

set loadpath 
set fontpath 
set psdir
set fit noerrorvariables

GNUTERM = "qt"

p "./data/HdepVSNnodes.java.dat" matrix with image, "data/LdepVSNnodes.log.java.dat" w lp lc 2 ps 3 pt 3 lw 3

#    EOF
