#include <iostream>
#include "/opt/NR/numerical_recipes.c/gauleg.c"
#include "/opt/NR/numerical_recipes.c/gauher.c"
#include "/opt/NR/numerical_recipes.c/gaulag.c"
#include "/opt/NR/numerical_recipes.c/nrutil.c"
#include "/opt/NR/numerical_recipes.c/nrutil.h"
#include "/opt/NR/numerical_recipes.c/gammln.c"
#include <math.h>
#include <stdio.h>


void GaussLegandre (double (*f)(double arg),int n,float a,float b,FILE *,float dokladna);
void GaussHermit (double (*f)(double arg),int n,float a,float b,FILE *fp);
void GaussLaugere (double (*f)(double arg),int n,float a,float b,FILE *fp,float dokladna);

double f1 (double arg);
double f2 (double arg);
double f3 (double arg);
double f22 (double arg);

int main ()
{
	float a, b;
	a=1.0;
	b=2.0;

	FILE *fp = fopen ("GaussLegandre.dat","w");

	for (int N=2;N<=100;N++)
	{
		GaussLegandre(f1,N,a,b,fp,M_PI/3.0);
	}
	fclose (fp);



	fp = fopen ("GaussHermit.dat","w");
	a = 0;
	b= 0;

	for (int N=2;N<=100;N+=2)
	{
		GaussHermit(f2,N,a,b,fp);
	}
	fclose (fp);



	fp = fopen ("GaussLegandre2.dat","w");
	a = 0;
	b= 5;

	for (int N=2;N<=100;N++)
	{
		GaussLegandre(f22,N,a,b,fp,-0.8700577);
	}
	fclose (fp);


	fp = fopen ("GaussLaugere.dat","w");
	a = 0;
	b= 5;

	for (int N=2;N<=10;N++)
	{
		GaussLaugere(f3,N,a,b,fp,2/13.0);
	}
	fclose (fp);

}


double f1 (double arg)
{
	return 1.0/(arg*sqrt(pow(arg,2)-1));
}

double f2 (double arg)
{
	return log(fabs(arg));
}

double f22 (double arg)
{
	return log(arg)*exp(-pow(arg,2));
}

double f3 (double arg)
{
	return sin(2*arg)*exp(-2*arg);
}

void GaussLegandre (double (*f)(double arg),int n,float a,float b,FILE *fp,float dokladna)
{
	float wartosc_dokladna = dokladna;
	float sum = 0.0;


		float *x = vector(1,n);
		float *w = vector(1,n);

		gauleg (a,b,x,w,n);


		for (int i=1;i<=n;i++)
			sum += w[i] * f(x[i]);


		free_vector(x,1,n);
		free_vector(w,1,n);


	fprintf(fp,"%f\n",fabs(wartosc_dokladna - sum));
}

void GaussHermit (double (*f)(double arg),int n,float a,float b,FILE *fp)
{
	float wartosc_dokladna = -0.8700577;
	float sum = 0.0;


		float *x = vector(1,n);
		float *w = vector(1,n);

		gauher (x,w,n);


		for (int i=1;i<=n;i++)
			sum += w[i] * f(x[i]);
			sum/=2.0;

		free_vector(x,1,n);
		free_vector(w,1,n);

	fprintf(fp,"%f\n",fabs(wartosc_dokladna - sum));
}

void GaussLaugere (double (*f)(double arg),int n,float a,float b,FILE *fp,float dokladna)
{
	float wartosc_dokladna = dokladna;
	float sum = 0.0;


		float *x = vector(1,n);
		float *w = vector(1,n);

		gaulag (x,w,n,0);


		for (int i=1;i<=n;i++)
			sum += w[i] * f(x[i]);


		free_vector(x,1,n);
		free_vector(w,1,n);


	fprintf(fp,"%f\n",fabs(wartosc_dokladna - sum));
}


