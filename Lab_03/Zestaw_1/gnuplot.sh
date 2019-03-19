set terminal post enhanced colour solid font 20  # wybor formatu, w jakim chcemy utworzyc wynikowy rysunek
set terminal jpeg

set output "x_t.jpg" # nazwa pliku wynikowego
set title "Ruch ciala" # tytul wykresu
set xlabel "t" # etykieta osi OX
set ylabel "x(t)" # etykieta osi OY
set grid # wlaczenie widoczności siatki pomocniczej
plot "Przypadek_1.dat" w p t "beta = 0.0, F0 = 0", cos(x) w l title "cos(t)"
# plot - polecenie rysowania pliku o podanej nazwie "out.dat"
# w p == with points
# t "dt = 0.1" == title "dt = 0.1"