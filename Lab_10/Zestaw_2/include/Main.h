#pragma once

#include <math.h>
#include <string>

const double R1 = (sqrt (5) - 1.0) / 2.0;
const double R2 = 1.0 / 3.0;
const double epsilon = pow (10, -6);

double function_1 (double arg);

double function_2 (double arg);

void
woof (double left_init, double right_init, double R, std::string str, double (*function) (double), double exact_value,bool choice);

