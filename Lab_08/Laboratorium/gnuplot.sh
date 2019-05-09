#!/usr/bin/env bash
set terminal post enhanced colour solid font 14  # wybor formatu, w jakim chcemy utworzyc wynikowy rysunek
set terminal jpeg
set output "danef1_a.dat" # nazwa pliku wynikowego
set title "Interpolacja funkcji I kubicznymi funkcjami sklejanymi dla 5 wezlow" # tytul wykresu
set xlabel "argumenty funkcji" # etykieta osi OX
set ylabel "wartosci funkcji" # etykieta osi OY
set grid # wlaczenie widoczności siatki pomocniczej
#set xrange [-11:11]
plot 'danef1_a.dat' using 1:2 with lines title "wykres funkcji",'danef1_a.dat' using 1:3 with points title "interpolacja"
#replot "cmake-build-debug/dane.dat" using 1:3 with points


# plot - polecenie rysowania pliku o podanej nazwie "out.dat"
# w p == with points
# t "dt = 0.1" == title "dt = 0.1"