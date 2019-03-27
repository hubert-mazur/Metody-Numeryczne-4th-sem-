set term png
set view map
set pm3d interpolate 4,4
set out "vec_NUMER.png"
#splot "dane.dat" u 1:2:NUMER w pm3d
do for [t=3:12] {
  #outfile = sprintf('animation/bessel%03.0f.png',t)
  #set output outfile
  #splot u*sin(v),u*cos(v),bessel(u,t/50.0) w pm3d ls 1
	set out "vec_".((t-2)).".png"
  splot "dane.dat" u 1:2:t w pm3d

}