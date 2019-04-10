//
// Created by hubert on 09.04.19.
//

#ifndef LAB08_FUNCTIONS_H
#define LAB08_FUNCTIONS_H

#include "math.h"
#include <iostream>
#include <stdio.h>

void fill_function_values (const double *args, double *values, int N);

void difference_quotient (const double *args, const double *values, double ***result, int N);

double interpolate (double *args, double **difference_arr, int N, double value);


#endif //LAB08_FUNCTIONS_H
