#pragma once

#include <iostream>
#include <math.h>
#include <string>

const double dx = 0.01;

const double f1_get_value(const double arg)
{
    return 1.0 / (1.0 + pow(arg, 2));
}

void f1_fill_array(double *array, double *args,int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = 1.0 / (1.0 + pow(args[i], 2));
    }
}

const double f2_get_value(const double arg)
{
    return cos(2*arg);
}

void f2_fill_array(double *array, double *args,int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = cos(2*args[i]);
    }
}

double f1_derivate (const double arg)
{
    return (f1_get_value(arg+dx)-f1_get_value(arg-dx))/(2*dx);
}