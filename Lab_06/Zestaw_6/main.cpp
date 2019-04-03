#include <iostream>
#include <stdio.h>
#include <math.h>
double reszta (const double *a, double *b, int n, double xj)
{
	double Rj;
	b[n] = 0;
	for (int k = n - 1; k >= 0; k--)
	{
		b[k] = a[k+1] + xj * b[k+1];
	}
	Rj = a[0] + xj*b[0];
	return Rj;
}

int main ()
{
	FILE *fp;

	fp = fopen ("dane.dat","w");
	if (!fp)
		exit (-2);

	fprintf (fp,"L ---- it ---- x2 ---- R2\n");

	const int N = 5;
	const int IT_MAX = 30;
	double a [N+1];
	double b [N+1];
	int n;
	double x0, x1, R0, R1,x2,R2;
	a[0] = 240;
	a[1] = -196;
	a[2] = -92;
	a[3] = 33;
	a[4] = 14;
	a[5] = 1;

	for (int i = 1;i<=N;i++)
	{
		n = N-i+1;
		x0 = 0;
		x1 = 0.1;
		R0 = reszta (a,b,n,x0);
		R1 = reszta (a,b,n,x1);

		for (int j = 1; j<=IT_MAX;j++)
		{
			x2 = x1 - (R1*(x1-x0)/(R1-R0));
			R2 = reszta (a,b,n,x2);
			R0 = R1;
			R1 = R2;
			x0 = x1;
			x1 = x2;
			fprintf (fp,"%d ---- %d ---- %lf ---- %lf\n",i,j,x2,R2);
			if (abs (x1-x0)< pow(10,-7))
				break;
		}
		fprintf (fp,"\n\n");
		for (int i=0;i<= n-1;i++)
			a[i] = b[i];
	}

fclose (fp);
}