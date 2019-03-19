 #include "/home/hubert/Numerical_recipes/nrutil.h"
 #include "/home/hubert/Numerical_recipes/nrutil.cpp"
//#include "/opt/NR/numerical_recipes.c/nrutil.h"
//#include "/opt/NR/numerical_recipes.c/nrutil.c"
#include "math.h"
#include <iostream>
#include <stdio.h>
#define V0 0
#define x0 1
#define w 1
#define N 2000
#define h 0.02
double break_condition (double *xn);
void Jakobi(double B, double F0, double omega);

int main()
{
  double B, F0, omega;
  ///// case 1 /////
  // B = 0.0;
  // F0 = 0.0;
  // omega = 0.8;
  // Jakobi(B, F0, omega);
  ///// case 2 ////
  // B = 0.4;
  // F0 = 0.0;
  // omega = 0.8;
  // Jakobi(B, F0, omega);
///// case 3 ////
  B = 0.4;
  F0 = 0.1;
  omega = 0.8;
  Jakobi(B, F0, omega);
   return 0;
}

void Jakobi(double B, double F0, double omega)
{
  std::cout << "B = " << B << ", F0 = " << F0 << ", omega = " << omega << std::endl;

  double a1 = 1;
  double a2 = w * w * h * h - 2 - B * h;
  double a3 = 1 + B * h;

  double *d0 = new double [N+1];
  double *d1 = new double [N+1];
  double *d2 = new double [N+1];
  double *b = new double [N+1];

  //inicjalizacja wektorow
  for (int i = 0; i < N; i++)
  {
    d0[i] = a3;
    d1[i] = a2;
    d2[i] = a1;
    b[i] = F0 * sin(omega * h * i) * h * h;
  }
  d0[0] = 1.0;
  d0[1] = 1.0;
  d1[0] = 0.0;
  d1[1] = -1.0;
  d2[0] = 0.0;
  d2[1] = 0.0;
  b[0] = 1.0;
  b[1] = 0.0;

  //wypisz pierwsze 5 elementow wektorow
  std::cout << "\nd0  d1  d2  b\n" ;
  for (int i = 0; i < 10; i++)
	printf ("%2f  %2f  %2f  %2f\n",d0[i],d1[i],d2[i],b[i]);
  double *xn = new double [N+2];
  double *xs = new double [N+2];
  for (int i=0;i<N;i++)
  {
	  xn[i]=0;
	  xs[i]=0;
  }
  xs[N]=0;
  xs[N+1]=0;
  xn[N]=0;
  	
	xs[0]=0.25; // losowa liczba
	xs[1]=0.3; // losowa liczba
	xs = xs+2;
	int iteration=1;
  
	while (iteration < 10000)
	{
     for (int i = 0; i <= N; i++)
       xn[i] = (1 / d0[i]) * (b[i] - d1[i] * xs[i - 1] - d2[i] * xs[i - 2]);

	  iteration++;
	  double sum_xs=0;
	  double sum_xn=0;

	for (int i=0;i<N;i++)
	{
		sum_xs+=pow(xs[i],2);
		sum_xn+=pow(xn[i],2);
	}
	if (abs(sum_xn-sum_xs) < pow(10,-6))
	break;
		    for (int i = 0; i < N; i++)
      xs[i] = xn[i];
	  // std::cout<<"iteration: "<<iteration<<"\n";
  	}

	FILE *file_ptr;
	file_ptr = fopen ("Przypadek_3.dat","w");// tutaj zmieniamy realizowany przypadek
	if (!file_ptr)
	{
		printf("ERR while opening file! Leaving!\n"); 
		return;
	}
double start = 0.0;
  for (int i = 0; i < N; i++)
  {
    fprintf(file_ptr, "%f   %f\n", start, xn[i]);
    start += h;
  }

delete [] d0;
delete [] d1;
delete [] d2;
delete [] xn;
xs = xs-2;
delete [] xs;
delete [] b;
 fclose(file_ptr);
}
double break_condition (double *xn)
{
	double suma=0;
	for (int i=0;i<N;i++)
	{
		suma+=xn[i]*xn[i];
	}
	return suma;
}
