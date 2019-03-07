set terminal post enhanced colour solid font 20  # wybor formatu, w jakim chcemy utworzyc wykres

set output "x_t.eps" # nazwa pliku wynikowego
set title "Rozwiazanie rownania Poissona w jednym wymiarze" # tytul wykresu
set xlabel "t" # etykieta osi OX
set ylabel "x(t)" # etykieta osi OY
set grid # wlaczenie widoczności siatki pomocniczej
plot "out_NR.dat" w p t "numerical values"
replot "out_TR.dat" w l t "real values"
# plot - polecenie rysowania pliku o podanej nazwie "out.dat"
# w p == with points
# t "dt = 0.1" == title "dt = 0.1"
