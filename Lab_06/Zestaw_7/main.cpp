#include <iostream>
#include <complex.h>
#include <math.h>

double _Complex licz_Rj (double _Complex *a,double _Complex *b, int N, double _Complex zj)
{
	double _Complex Rj;
	b[N] = 0;
	for (int k=N-1; k>=0;k--)
	{
		b[k] = a[k+1] + zj*b[k+1];
	}
	Rj = a[0] + zj*b[0];
	return Rj;
}

double _Complex licz_Rjj (double _Complex *c,const double _Complex *b, int N, double _Complex zj)
{
	double _Complex Rjj;
	c[N-1] = 0;
	for (int k = N-2;k>=0;k--)
	{
		c[k] = b[k+1] + zj*c[k+1];
	}
	Rjj = b[0] + zj*c[0];
	return Rjj;
}

int main ()
{
	const int N = 4;
	const int IT_MAX = 30;
	double _Complex a[N + 1];
	double _Complex c[N + 1];
	double _Complex b[N + 1];
	double _Complex z0;
	double _Complex zj;
	double _Complex Rj;
	double _Complex Rjj;

	a[0] = 16 + 8I;
	a[1] = -20 + 14I;
	a[2] = 4 - 8I;
	a[3] = -4 + I;
	a[4] = 1 + 0I;


	z0 = 0 + 0I;

	for (int l = N; l >= 1; l--)
	{
		zj = z0;

		{
			for (int j =1;j<=IT_MAX;j++)
			{
				Rj = licz_Rj (a,b,l,zj);
				Rjj = licz_Rjj (a,c,l-1,zj);
				zj = z0 - (Rj/Rjj);
				z0 = zj;
			}
			for (int i=0;i<=N;i++)
				a[i] = b[i];
			std::cout<<creal (zj)<<" "<<cimag (zj)<<std::endl;
		}
	}
}