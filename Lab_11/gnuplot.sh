#!/usr/bin/env bash
set terminal post enhanced colour solid font 14  # wybor formatu, w jakim chcemy utworzyc wynikowy rysunek
set terminal jpeg

set xlabel "Numer iteracji" # etykieta osi OX
set ylabel "Wartosc" # etykieta osi OY
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
set title "sygnal zaburzony i odszumiony k=8" # tytul wykresu
set output "sygnal_zaburzony_i_odszumiony_k=8.jpg" # nazwa pliku wynikowego

plot '8_sygnal_zaburzony_i_odszumiony.dat' using 1:2 with lines title "zaszumiony" ls 1, '8_sygnal_zaburzony_i_odszumiony.dat' using 1:3 with lines ls 2 title "odszumiony"
#############################################################################################################
set title "sygnal niezaburzony i odszumiony k=8" # tytul wykresu
set output "sygnal_niezaburzony_i_odszumiony_k=8.jpg" # nazwa pliku wynikowego

plot '8_sygnal_niezaburzony_i_odszumiony.dat' using 1:2 with lines title "zaszumiony" ls 1, '8_sygnal_niezaburzony_i_odszumiony.dat' using 1:3 with lines ls 2 title "odszumiony"
#############################################################################################################

#############################################################################################################
set title "sygnal zaburzony i odszumiony k=10" # tytul wykresu
set output "sygnal_zaburzony_i_odszumiony_k=10.jpg" # nazwa pliku wynikowego

plot '10_sygnal_zaburzony_i_odszumiony.dat' using 1:2 with lines title "zaszumiony" ls 1, '10_sygnal_zaburzony_i_odszumiony.dat' using 1:3 with lines ls 2 title "odszumiony"
#############################################################################################################
set title "sygnal niezaburzony i odszumiony k=10" # tytul wykresu
set output "sygnal_niezaburzony_i_odszumiony_k=10.jpg" # nazwa pliku wynikowego

plot '10_sygnal_niezaburzony_i_odszumiony.dat' using 1:2 with lines title "zaszumiony" ls 1, '10_sygnal_niezaburzony_i_odszumiony.dat' using 1:3 with lines ls 2 title "odszumiony"
#############################################################################################################

#############################################################################################################
set title "sygnal zaburzony i odszumiony k=12" # tytul wykresu
set output "sygnal_zaburzony_i_odszumiony_k=12.jpg" # nazwa pliku wynikowego

plot '12_sygnal_zaburzony_i_odszumiony.dat' using 1:2 with lines title "zaszumiony" ls 1, '12_sygnal_zaburzony_i_odszumiony.dat' using 1:3 with lines ls 2 title "odszumiony"
#############################################################################################################
set title "sygnal niezaburzony i odszumiony k=12" # tytul wykresu
set output "sygnal_niezaburzony_i_odszumiony_k=12.jpg" # nazwa pliku wynikowego

plot '12_sygnal_niezaburzony_i_odszumiony.dat' using 1:2 with lines title "zaszumiony" ls 1, '12_sygnal_niezaburzony_i_odszumiony.dat' using 1:3 with lines ls 2 title "odszumiony"
#############################################################################################################
set title "czesc rzeczywista i urojona k=8" # tytul wykresu
set output "czesc_rzeczywista_i_urojona_k=8.jpg" # nazwa pliku wynikowego

plot 'k=8_moduly.dat' using 1:2 with lines title "rzeczywista" ls 1, 'k=8_moduly.dat' using 1:3 with lines ls 2 title "urojona"
#############################################################################################################
set title "Moduł liczby zespolonej" # tytul wykresu
set output "modul_liczb_zespolonych_k=8.jpg" # nazwa pliku wynikowego

plot 'k=8_moduly.dat' using 1:4 with lines title "moduł liczb zespolonych" ls 1
#############################################################################################################
