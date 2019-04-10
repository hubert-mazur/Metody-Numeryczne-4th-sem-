#!/usr/bin/env bash
set terminal post enhanced colour solid font 20  # wybor formatu, w jakim chcemy utworzyc wynikowy rysunek
set output "cos.eps" # nazwa pliku wynikowego
set title "nwm" # tytul wykresu
set xlabel "args" # etykieta osi OX
set ylabel "values" # etykieta osi OY
set grid # wlaczenie widoczności siatki pomocniczej
#set xrange [-11:11]

plot 'cmake-build-debug/dane.dat' using 1:2 with lines title "wykres funkcji", 'cmake-build-debug/dane.dat' using 1:3 with points title "dopasowanie metoda interpolacji"
#replot "cmake-build-debug/dane.dat" using 1:3 with points


# plot - polecenie rysowania pliku o podanej nazwie "out.dat"
# w p == with points
# t "dt = 0.1" == title "dt = 0.1"