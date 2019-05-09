#!/usr/bin/env bash
set terminal post enhanced colour solid font 14  # wybor formatu, w jakim chcemy utworzyc wynikowy rysunek
set terminal jpeg
set output "wykres_f1.jpg" # nazwa pliku wynikowego
set title "Aproksymacja" # tytul wykresu
set xlabel "argumenty funkcji" # etykieta osi OX
set ylabel "wartosci funkcji" # etykieta osi OY
set grid # wlaczenie widoczności siatki pomocniczej

#set xrange [-11:11]


plot 'dane_f1.dat' using 1:2 with lines title "wykres funkcji", 'dane_f1.dat' using 1:3 with points title "aproksymacja1"

set output "wykres_f2.jpg" # nazwa pliku wynikowego
plot 'dane_f2.dat' using 1:2 with lines title "wykres funkcji", 'dane_f2.dat' using 1:3 with points title "aproksymacja3"

set output "wykres_f3_1.jpg" # nazwa pliku wynikowego
plot 'dane_f3_1.dat' using 1:2 with lines title "wykres funkcji", 'dane_f3_1.dat' using 1:3 with points title "aproksymacja3_1"

set output "wykres_f3_2.jpg" # nazwa pliku wynikowego
plot 'dane_f3_2.dat' using 1:2 with lines title "wykres funkcji", 'dane_f3_2.dat' using 1:3 with points title "aproksymacja3_2"

set output "wykres_f3_3.jpg" # nazwa pliku wynikowego
plot 'dane_f3_3.dat' using 1:2 with lines title "wykres funkcji", 'dane_f3_3.dat' using 1:3 with points title "aproksymacja3_3"

set output "wykres_f1_alpha_1.jpg" # nazwa pliku wynikowego
plot 'dane_f1_alpha_1.dat' using 1:2 with lines title "wykres funkcji", 'dane_f1_alpha_1.dat' using 1:3 with points title "aproksymacja1_alpha_1"

set output "wykres_f1_alpha_2.jpg" # nazwa pliku wynikowego
plot 'dane_f1_alpha_2.dat' using 1:2 with lines title "wykres funkcji", 'dane_f1_alpha_2.dat' using 1:3 with points title "aproksymacja1_alpha_2"

# plot - polecenie rysowania pliku o podanej nazwie "out.dat"
# w p == with points
# t "dt = 0.1" == title "dt = 0.1"