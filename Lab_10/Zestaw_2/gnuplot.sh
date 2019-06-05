#!/usr/bin/env bash
set terminal post enhanced colour solid font 14  # wybor formatu, w jakim chcemy utworzyc wynikowy rysunek
set terminal jpeg

set xlabel "Numer iteracji" # etykieta osi OX
set ylabel "Bezwzgledna roznica rozwiazania dokladnego i przyblizonego" # etykieta osi OY
set grid # wlaczenie widoczności siatki pomocniczej


set style line 1  lc rgb 'red' lt 1 lw 2 # --- blue
set style line 2  lc rgb 'blue' lt 1 lw 2 #      .
set style line 3  lc rgb 'black' lt 1 lw 2 #      .
set style line 4  lc rgb 'green' lt 1 lw 2 #      .
set style line 5  lc rgb 'yellow' lt 1 lw 2 #      .
set style line 6  lc rgb 'violet' lt 1 lw 2 #      .
set style line 7  lc rgb 'orange' lt 1 lw 2 #      .
set style line 8  lc rgb 'pink' lt 1 lw 2 #      .
set style line 9 lc rgb 'grey' lt 1 lw 2 #      .



################################################### DRAW ####################################################

#############################################################################################################
set title "roznica rozwiazan funkcji f(x)" # tytul wykresu
set output "f(x)_1.jpg" # nazwa pliku wynikowego
set logscale y
plot 'cmake-build-debug/f(x)_1.dat' using 1:3 with lines title "r=(sqrt(5)-1)/2" ls 1, 'cmake-build-debug/f(x)_2.dat' using 1:3 with lines ls 2 title "r=1/3"
#############################################################################################################
set title "roznica rozwiazan funkcji g(x)" # tytul wykresu
set output "g(x)_1.jpg" # nazwa pliku wynikowego
set logscale y
plot 'cmake-build-debug/g(x)_1.dat' using 1:3 with lines title "r=(sqrt(5)-1)/2" ls 1, 'cmake-build-debug/g(x)_2.dat' using 1:3 with lines ls 2 title "r=1/3"
#############################################################################################################
