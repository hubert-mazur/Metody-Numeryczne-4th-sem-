#!/usr/bin/env bash
set terminal post enhanced colour solid font 14  # wybor formatu, w jakim chcemy utworzyc wynikowy rysunek
set terminal jpeg
set output "wykres1.jpg" # nazwa pliku wynikowego
set title "Interpolacja Newtona dla rownoodleglych wezlow" # tytul wykresu
set xlabel "argumenty funkcji" # etykieta osi OX
set ylabel "wartosci funkcji" # etykieta osi OY
set grid # wlaczenie widoczności siatki pomocniczej
#set xrange [-11:11]
plot 'cmake-build-debug/dane.dat' using 1:2 with lines title "wykres funkcji", 'cmake-build-debug/dane.dat' using 1:3 with points title "dopasowanie metoda interpolacji"
#replot "cmake-build-debug/dane.dat" using 1:3 with points


# plot - polecenie rysowania pliku o podanej nazwie "out.dat"
# w p == with points
# t "dt = 0.1" == title "dt = 0.1"