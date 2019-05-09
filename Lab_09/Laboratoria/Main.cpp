
#include <iostream>
#include <math.h>
#include <time.h>

const double min = 0;
const double max = 2*M_PI;
const int n = 100;
int MC;
int MS;
bool print_a_b = 0;

double f1 (double arg);
double f2 (double arg);
double f3 (double arg);
double f1_alpha (double arg);
double approx (double *a, double *b, int MS, int MC, double arg);
double szum ();


void All (int MS, int MC, double (*fun)(double),const char *str);


int main ()
{
	MC = 5;
	MS = 5;

	All(5,5,f1,"dane_f1.dat");
	All(5,5,f2,"dane_f2.dat");
	All(5,0,f3,"dane_f3_1.dat");
	All(5,5,f3,"dane_f3_2.dat");
	All(10,10,f3,"dane_f3_3.dat");

	print_a_b  = true;

	All(5,5,f1_alpha,"dane_f1_alpha_1.dat");
	All(30,30,f1_alpha,"dane_f1_alpha_2.dat");

}



double f1 (double arg)
{
	return (2*sin(arg)+sin(2*arg)+2*sin(3*arg));
}


double f2 (double arg)
{
	return (2*sin(arg)+sin(2*arg)+ 2*cos(arg) + cos(2*arg));
}

double f3 (double arg)
{
	return (2*sin(1.1*arg) + sin(2.1*arg) + 2*sin(3.1*arg));
}

double f1_alpha (double arg)
{
	return (2*sin(arg)+sin(2*arg)+2*sin(3*arg) + szum());
}


double szum ()
{
	srand(time(NULL));
	return ((rand())/(RAND_MAX+1.0)-0.5);
}

double approx (double *a, double *b, int MS, int MC, double arg)
{
	double sum = 0;

	for (int i=0;i<=MS;i++)
	{
		sum += a[i]*sin(i*arg);
	}

	for (int i=0;i<=MC;i++)
	{
		sum += b[i]*cos(i*arg);
	}
}

void All (int MS, int MC, double (*fun)(double),const char *str)
{
	double argumenty_f [n];
	double wartosci_f [n];

	argumenty_f[0] = min;
	argumenty_f[n-1] = max;
	double interval = ((max-min)/(n-1.0));

	for (int i=1;i<n-1;i++)
		argumenty_f[i] = argumenty_f[i-1] + interval;

	for (int i=0;i<n;i++)
		wartosci_f[i] =  fun (argumenty_f[i]);

		double a[MS+1];
		double b[MC+1];

	double sum;

	for (int i=0;i<=MS;i++)
	{
		sum = 0;

		a[i]=2.0/n;
		for (int j=0;j<n;j++)
			sum += wartosci_f[j] * sin(i*argumenty_f[j]);
		a[i] *= sum;
	}

	for (int i=0;i<=MC;i++)
	{
		sum = 0;

		b[i] = 2.0/n;

		for (int j=0;j<n;j++)
			sum += wartosci_f[j] * cos(i*argumenty_f[j]);
		b[i] *= sum;
	}

	std::cout<<"wspolczynniki a i b: "<<std::endl;

	if (print_a_b)
	{
		for (int i=0;i<MS;i++)
		{
			printf ("%d %lf %lf\n",i,a[i],b[i]);
		}
		std::cout<<std::endl<<std::endl;
	}


	FILE *file = fopen (str,"w");

	for (double i=0;i<max;i+= 0.01)
		fprintf (file,"%lf %lf %lf\n",i,fun(i),approx(a,b,MS,MC,i));

}

