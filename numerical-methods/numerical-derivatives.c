#include <stdio.h>
#include <math.h>

double function(double x) {
	return sin(x);
}

double derivativeFunction(double x) {
	double h = 1e-1;
	return (function(x + h) - function(x)) / h;
}

int main() {
	double x = M_PI / 4;
	printf("F(x)     =  sin(%.2f) = %.8f\n", x, function(x));
	printf("f(x)     ~= numerisch = %.8f\n", derivativeFunction(x));
	printf("f_exact  =  cos(%.2f) = %.8f\n", x, cos(x));
	return 0;
}
