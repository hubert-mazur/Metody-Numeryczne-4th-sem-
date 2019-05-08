#include <iostream>
#include <math.h>
#include <string>
#include "/home/hubert/gsl/include/gsl/gsl_linalg.h"
#include "/home/hubert/gsl/include/gsl/gsl_matrix.h"

const double lamba = 0.5;
const double mi = 0.5;
const double alpha = 0;
const double beta = 0;

double f1(double args);
double f2(double args);
double wyznacz_Sx(double *xw, double *yw, double *m, int n, double x);
void wyznacz_M(double *xw, double *yw, double *m, int n, double alpha, double beta);
double derivate(double args);
void special(int n);

int main()
{
	int tab[]{5, 8, 21};
	std::string funct = "f2";
	for (int i = 0; i < 3; i++)
	{

		int n = tab[i];

		double h = 10.0 / (double)(n - 1);

		double xw[n];
		double yw[n];
		double m[n];

		xw[0] = -5;
		xw[n - 1] = 5;

		for (int i = 1; i < n - 1; i++)
			xw[i] = xw[i - 1] + h;

		for (int i = 0; i < n; i++)
			yw[i] = f2(xw[i]);

		wyznacz_M(xw, yw, m, n, alpha, beta);

		FILE *fp;

		std::string str = "dane_" + funct + std::to_string(i) + ".dat";

		fp = fopen(str.c_str(), "w");

		for (double i = -5.0; i <= 5.0; i += 0.01)
		{
			fprintf(fp, "%lf %lf %lf\n", i, f2(i+1), wyznacz_Sx(xw, yw, m, n, i));
		}

		fclose(fp);
	}
	special(10);

	return 0;
}

double wyznacz_Sx(double *xw, double *yw, double *m, int n, double x)
{
	int i = 666;
	double h = 10.0 / (double)(n - 1);

	for (int c = 0; c < n - 1; c++)
	{
		// std::cout <<xw[c]<<" < "<<x << "< "<<xw[c+1]<<std::endl;
		if (x >= xw[c] && x <= xw[c + 1])
			i = c;
	}
	try
	{
		if (i == 666)
			throw i;
	}

	catch (int)
	{
		std::cout << "could not find proper interval!\n";
		exit(-1);
	}

	double sx = 0;

	sx += m[i] * ((pow(xw[i + 1] - x, 3)) / (6 * h));
	sx += m[i + 1] * ((pow(x - xw[i], 3)) / (6 * h));
	sx += (x - xw[i]) * ((yw[i + 1] - yw[i]) / (h) - ((h / 6.0) * (m[i + 1] - m[i])));
	sx += yw[i] - m[i] * (pow(h, 2) / 6.0);

	return sx;
}

void wyznacz_M(double *xw, double *yw, double *m, int n, double alpha, double beta)
{
	double h = 10.0 / (double)(n - 1);
	double dx = 0.01;

	gsl_vector *d = gsl_vector_calloc(n);

	gsl_vector_set(d, 0, alpha);
	gsl_vector_set(d, n - 1, beta);

	for (int i = 1; i < n - 1; i++)
		gsl_vector_set(d, i, (6.0 / (2 * h)) * ((yw[i + 1] - yw[i]) / (h) - (yw[i] - yw[i - 1]) / (h)));

	gsl_matrix *A = gsl_matrix_calloc(n, n);

	gsl_matrix_set(A, 0, 0, 1);
	gsl_matrix_set(A, n - 1, n - 1, 1);

	for (int i = 1; i <= n - 2; i++)
		gsl_matrix_set(A, i, i, 2);

	for (int i = 0; i < n - 1; i++)
		gsl_matrix_set(A, i + 1, i, 0.5);

	for (int i = 2; i <= n - 1; i++)
		gsl_matrix_set(A, i - 1, i, 0.5);

	gsl_matrix_set(A, n - 1, n - 2, 0);

	// for (int i=0;i<n;i++)
	// 	{
	// 		for (int j=0;j<n;j++)
	// 			std::cout<<gsl_matrix_get(A,i,j)<<" ";
	// 		std::cout<<std::endl;
	// 	}

	gsl_linalg_HH_svx(A, d);

	for (int i = 0; i < n; i++)
		std::cout << gsl_vector_get(d, i) << std::endl;

	for (int i = 0; i < n; i++)
	{
		m[i] = (f2(xw[i] - dx) - 2 * f2(xw[i]) + f2(xw[i] + dx)) / (pow(dx, 2));
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++)
		std::cout << m[i] << std::endl;

	for (int i = 1; i < n - 1; i++)
		m[i] = gsl_vector_get(d, i);

	gsl_matrix_free(A);
	gsl_vector_free(d);
}

void special(int n)
{
	FILE *fp = fopen("derivtes.dat", "w");

	double h = 10.0 / (double)(n - 1);

	double xw[n];
	double yw[n];
	double m[n];

	xw[0] = -5;
	xw[n - 1] = 5;

	for (int i = 1; i < n - 1; i++)
		xw[i] = xw[i - 1] + h;

	for (int i = 0; i < n; i++)
		yw[i] = f1(xw[i]);

	wyznacz_M(xw, yw, m, n, alpha, beta);

	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%i %lf %lf\n", i, derivate(xw[i]), m[i]);
	}
	fclose(fp);
}

double derivate(double args)
{
	double temp = 0.0;
	temp += f2(args - 0.01);
	temp -= 2 * f2(args);
	temp += f2(args + 0.01);
	temp /= pow(0.01, 2);

	return temp;
}

double f1(double args)
{
	return 1.0 / (1.0 + pow(args, 2));
}

double f2(double args)
{
	return cos(2 * args);
}