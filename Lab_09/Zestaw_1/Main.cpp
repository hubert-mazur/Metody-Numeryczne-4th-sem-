#include "Main.h"

const double max = 4.0;
const double min = -4.0;
const double x0 = 2.0;
const double sigma = fraction(max-min,16);
const int n = 201;
const int m[3] {10,30,50};

int main ()
{   
    for (auto i:m)
    {
    int wezly [201];


    wezly[0] = min;
    wezly[n-1]=max;
    double interval = fraction(max-min,n-1);
    for (int i=1;i<n-1;i++)
    {
        wezly[i] = wezly[i-1] + interval;
    }



    }
}

double function (double argument)
{
    double temp = 1;
    temp *= sin(fraction(14*M_PI*argument,max-min));
    temp *= (exp(-fraction(pow(argument-x0,2),2*pow(sigma,2)))+exp(-fraction(pow(argument+x0,2),2*pow(sigma,2))));
    return temp;
}


double fraction (double x, double y)
{
    return x/y;
}

double main_function (double argument)
{
    return function(argument) + fraction(frand()-0.5,5);
}