#include <iostream>
#include "Main.h"


int main ()
{
	woof (-0.5, 1.0, R1, "f(x)_1.dat", &function_1, -0.1673198,false);
	woof (-0.5, 1.0, R2, "f(x)_2.dat", &function_1, -0.1673198,true);
	woof (-4.0, 1.0, R1, "g(x)_1.dat", &function_2, 0.0,false);
	woof (-4.0, 1.0, R2, "g(x)_2.dat", &function_2, 0.0,true);
}


double function_1 (double arg)
{
	return log (pow (arg, 5) + 3 * pow (arg, 2) + arg + 9);
}

double function_2 (double arg)
{
	return pow (arg, 6);
}

void
woof (double left_init, double right_init, double R, std::string str, double (*function) (double), double exact_value,bool choice)
{
	double x_a = left_init;
	double x_b = right_init;
	double x_1;
	double x_2;
	double x_min;
	int IT = 0;

	FILE *fp = fopen (&str[0], "w");

	while (true)
	{
		if (choice)
		{
			double interval = (x_b-x_a)/(3.0);
			x_1 = x_a+interval;
			x_2 = x_b - interval;
		}
		else
		{
		x_1 = x_a + pow (R, 2) * (x_b - x_a);
		x_2 = x_a + R * (x_b - x_a);
		}


		if (function (x_1) > function (x_2))
			x_a = x_1;
		else
			x_b = x_2;

		x_min = (x_1 + x_2) / 2.0;

		IT++;

		fprintf (fp, "%d %g %g\n", IT, x_min, fabs (x_min - exact_value));


		if ((fabs (x_1 - x_2)) < epsilon)
			break;
	}
	fclose (fp);

}
