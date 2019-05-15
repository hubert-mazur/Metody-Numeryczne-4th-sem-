#!/usr/bin/env bash
set terminal post enhanced colour solid font 14  # wybor formatu, w jakim chcemy utworzyc wynikowy rysunek
set terminal jpeg
set output "wykres_f1.jpg" # nazwa pliku wynikowego
#set title "Aproksymacja" # tytul wykresu
set xlabel "argumenty funkcji" # etykieta osi OX
set ylabel "wartosci funkcji" # etykieta osi OY
set grid # wlaczenie widoczności siatki pomocniczej

#set xrange [-11:11]
set style line 1  lc rgb 'red' lt 1 lw 2 # --- blue
set style line 2  lc rgb 'blue' lt 1 lw 2 #      .
set style line 3  lc rgb 'black' lt 1 lw 2 #      .
set style line 4  lc rgb 'green' lt 1 lw 2 #      .
set style line 5  lc rgb 'yellow' lt 1 lw 2 #      .
set style line 6  lc rgb 'violet' lt 1 lw 2 #      .
set style line 7  lc rgb 'orange' lt 1 lw 2 #      .
set style line 8  lc rgb 'pink' lt 1 lw 2 #      .
set style line 9 lc rgb 'grey' lt 1 lw 2 #      .
set style line 10 lc rgb '#00ad31' lt 1 lw 2 #      .
set style line 11 lc rgb '#00ad14' lt 1 lw 2 #      .
set style line 12 lc rgb '#09ad00' lt 1 lw 2 # --- green


set title "Aproksymacja funkcji 1." # tytul wykresu
set output "wykres_f1.jpg" # nazwa pliku wynikowego
plot 'dane_f1.dat' using 1:2 with lines title "wartosc funkcji" ls 1, 'dane_f1.dat' using 1:3 pt 7 ps 0.2 title "aproksymacja, MS=MC=5" 

set title "Aproksymacja funkcji 2." # tytul wykresu
set output "wykres_f2.jpg" # nazwa pliku wynikowego
plot 'dane_f2.dat' using 1:2 with lines title "wartosc funkcji" ls 1, 'dane_f2.dat' using 1:3 pt 7 ps 0.2 title "aproksymacja, MS=MC=5"

set title "Aproksymacja funkcji 3." # tytul wykresu
set output "wykres_f3.jpg" # nazwa pliku wynikowego
plot 'dane_f3_1.dat' using 1:2 pt 7 ps 0.2 title "wartosc funkcji", 'dane_f3_1.dat' using 1:3 with lines title "aproksymacja,MS=5,MC=0" ls 1,'dane_f3_2.dat' using 1:3 with lines title "aproksymacja,MS=5,MC=5" ls 3, 'dane_f3_1.dat' using 1:3 with lines title "aprolsymacja,MS=10,MC=10" ls 4

#set output "wykres_f3_1.jpg" # nazwa pliku wynikowego
#plot 'dane_f3_1.dat' using 1:2 with lines title "wykres funkcji", 'dane_f3_1.dat' using 1:3 with points title "aproksymacja3_1"

#set output "wykres_f3_2.jpg" # nazwa pliku wynikowego
#plot 'dane_f3_2.dat' using 1:2 with lines title "wykres funkcji", 'dane_f3_2.dat' using 1:3 with points title "aproksymacja3_2"

#set output "wykres_f3_3.jpg" # nazwa pliku wynikowego
#plot 'dane_f3_3.dat' using 1:2 with lines title "wykres funkcji", 'dane_f3_3.dat' using 1:3 with points title "aproksymacja3_3"

set title "Aproksymacja zaszumionej funkcji 1." # tytul wykresu
set output "wykres_f1_szum.jpg" # nazwa pliku wynikowego
plot 'dane_f1_alpha_1.dat' using 1:2 pt 7 ps 0.2 title "wartosc funkcji", 'dane_f1_alpha_1.dat' using 1:3 with lines title "MS=5, MC=5" ls 2, 'dane_f1_alpha_2.dat' using 1:3 with lines title "MS=MC=30" ls 3

set title "Wspolczynniki a i b, MS=5, MC=5" # tytul wykresu
set output "wspolczynniki_a_b_5.jpg" # nazwa pliku wynikowego
plot 'MS_5.dat' using 1:2 with lines title "a" ls 1, 'MS_5.dat' using 1:3 with lines title "b" ls 2

set title "Wspolczynniki a i b, MS=30, MC=30" # tytul wykresu
set output "wspolczynniki_a_b_30.jpg" # nazwa pliku wynikowego
plot 'MS_30.dat' using 1:2 with lines title "a" ls 1, 'MS_30.dat' using 1:3 with lines title "b" ls 2

#set output "wykres_f1_alpha_2.jpg" # nazwa pliku wynikowego
#plot 'dane_f1_alpha_2.dat' using 1:2 with lines title "wykres funkcji", 'dane_f1_alpha_2.dat' using 1:3 with points title "aproksymacja1_alpha_2"

# plot - polecenie rysowania pliku o podanej nazwie "out.dat"
# w p == with points
# t "dt = 0.1" == title "dt = 0.1"