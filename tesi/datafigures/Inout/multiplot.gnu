set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
set output "cppinout.eps"

set multiplot layout 1,2
set logscale
set xlabel "Degree"
set ylabel "Normalized frequency" offset 1.5
set ytics rotate
set rmargin 2
set key spacing 1.5

set key title "Project Adobe-Chromium (C++)"
p [][0.0001:1]"./data/N5323.8.adobe-chromium.0cpp.outd" pt 2 lc 1 title "Outdegree", exp(-1.7)*x**(-2.0) lc 1 lw 2 title "x^{-2.0}", "./data/N5323.8.adobe-chromium.0cpp.ind" title "Indegree" pt 2 lc 2, exp(-0.43)*x**(-3.) lc 2 lw 2 title "x^{-3.0}"
set key title "Project Youtube-h5vcc (C++)"
p [][0.0001:1]"./data/N9701.10.youtube-h5vcc.0cpp.outd" pt 2 lc 1 title "Outdegree", exp(-2)*x**(-1.9) lc 1 lw 2 title "x^{-1.9}", "./data/N9701.10.youtube-h5vcc.0cpp.ind" title "Indegree" pt 2 lc 2, exp(0.15)*x**(-3.5) lc 2 lw 2 title "x^{-3.5}"

unset multiplot

set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
set output "javainout.eps"

set multiplot layout 1,2
set logscale
set xlabel "Degree"
set ylabel "Normalized frequency" offset 1.5
set ytics rotate
set rmargin 2
set key spacing 1.5

set keytitle "Project Eclipse link (Java)"
p [][0.0001:1]"./data/N2744.5.eclipse-eclipselink.1java.outd" pt 2 lc 1 title "Outdegree", exp(-2.75)*x**(-1.6) lc 1 lw 2 title "x^{-1.6}", "./data/N2744.5.eclipse-eclipselink.1java.ind" title "Indegree" pt 2 lc 2, exp(0.13)*x**(-3.8) lc 2 lw 2 title "x^{-3.8}"
set keytitle "Project Openjdk (Java)"
p [][0.0001:1]"./data/N6020.8.uditrugman-openjdk8-jdk.7java.outd" pt 2 lc 1 title "Outdegree", exp(-2.5)*x**(-1.5) lc 1 lw 2 title "x^{-1.5}", "./data/N6020.8.uditrugman-openjdk8-jdk.7java.ind" title "Indegree" pt 2 lc 2, exp(0.21)*x**(-3.5) lc 2 lw 2 title "x^{-3.5}"

unset multiplot

set terminal postscript eps enhanced color solid "Helvetica" 18 blacktext size 15cm,7cm
set output "pyinout.eps"

set multiplot layout 1,2
set logscale
set xlabel "Degree"
set ylabel "Normalized frequency" offset 1.5
set ytics rotate
set rmargin 2
set key spacing 1.5

set keytitle "Project Openstack (Python)"
p [1:3000][0.0001:1]"./data/N4056.6.JiYou-openstack.0py.outd" pt 2 lc 1 title "Outdegree", exp(-2.5)*x**(-1.7) lc 1 lw 2 title "x^{-1.7}", "./data/N4056.6.JiYou-openstack.0py.ind" title "Indegree" pt 2 lc 2, exp(0.19)*x**(-5.0) lc 2 lw 2 title "x^{-5.0}"
set keytitle "Project PortableJeckyll (Python)"
p [1:3000][0.0001:1]"./data/N8219.7.madhur-PortableJekyll.3py.outd" pt 2 lc 1 title "Outdegree", exp(-2.3)*x**(-1.8) lc 1 lw 2 title "x^{-1.8}", "./data/N8219.7.madhur-PortableJekyll.3py.ind" title "Indegree" pt 2 lc 2, exp(0.3)*x**(-4.2) lc 2 lw 2 title "x^{-4.2}"

unset multiplot

