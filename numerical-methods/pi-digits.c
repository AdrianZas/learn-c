#include <stdio.h>
#include <math.h>

int main () {
	printf("How many decimal places do you want to calculate?\n");
	int n = 10000000;
	printf("Calculate pi with %d terms\n", n);

	double pi = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			pi += 1.0 / (2*i + 1);
		} else {
			pi -= 1.0 / (2*i + 1);
		}
	}
	pi *= 4;
	printf("%.15f\n", pi);
	printf("%.15f\n", M_PI);
}
