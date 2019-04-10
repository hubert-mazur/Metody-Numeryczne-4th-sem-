#!/usr/bin/env bash
set terminal post enhanced colour solid font 20  # wybor formatu, w jakim chcemy utworzyc wynikowy rysunek
set output "N10_op.eps" # nazwa pliku wynikowego
set title "Interpolacja f(x)=exp(-x^2) dla 10 wezlow z opt. ich polozenia" # tytul wykresu
set xlabel "args" # etykieta osi OX
set ylabel "values" # etykieta osi OY
set grid # wlaczenie widoczności siatki pomocniczej
set xrange [-6:6]
set yrange [:5]
plot 'cmake-build-debug/dane_op2.dat' using 1:2 with lines title "wykres funkcji", 'cmake-build-debug/dane_op2.dat' using 1:3 with points title "dopasowanie metoda interpolacji"
#replot "cmake-build-debug/dane.dat" using 1:3 with points


# plot - polecenie rysowania pliku o podanej nazwie "out.dat"
# w p == with points
# t "dt = 0.1" == title "dt = 0.1"