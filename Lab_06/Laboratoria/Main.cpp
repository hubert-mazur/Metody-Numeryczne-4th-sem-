#include <iostream>
#include <cmath>
double reszta_Rj (double *a, double *b,int n,double xj)
{
	double Rj;
		b[n] = 0;
	for (int k=n-1;k>=0;k--)
		b[k] = a[k+1] + xj*b[k+1];
	Rj = a[0] + xj*b[0];
	return Rj;
}



int main ()
{
	const int N = 5;
	double a[N+1];
	double b[N+1];
	double c[N+1];
	double Rj;
	double Rjj;
	double x1;
	double x0;
	const int IT_MAX = 30;
	int n;
	FILE *fp;
	fp = fopen ("dane.dat","w");
	if (!fp)
		exit(-1);


	a[0] = 240; 
	a[1] = -196; 
	a[2] = -92; 
	a[3] = 33; 
	a[4] = 14;
	a[5] = 1;

	fprintf(fp,"L --- it --- x1 --- Rj --- Rjj\n");

	for (int L=1;L<=N;L++)
	{
		n = N - L + 1;
		x0 = 0;

		for (int i=1;i<=IT_MAX;i++)
		{
			Rj = reszta_Rj(a,b,n,x0);
			Rjj = reszta_Rj(b,c,n-1,x0);
			x1 = x0 - Rj/Rjj;
			fprintf(fp,"%d --- %d --- %lf --- %lf --- %lf\n",L,i,x1,Rj,Rjj);
			
			if (fabs(x1 - x0)<pow(10,-7))
				break;
				x0 = x1;
		}
		std::cout<<"Znaleziono pierwiastek: "<<x1<<std::endl;
		fprintf(fp,"\n\n");
		for (int i=0;i<=n-1;i++)
			a[i] = b[i];
	}

	fclose (fp);
}