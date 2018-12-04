/*
 * Integrator.c
 *
 *  Created on: Dec 3, 2018
 *      Author: Kai
 */
#include "Integrator.h"

double getXj(double a, double h, double j) {
	return a + (h * j);
}

double shortenedSimpsonIntegral(Function& f, double a, double b, double n, double eps) {
	double sum1;
	double sum2;
	double h = (b - a) / n;

	for (int j = 1; j <= n-1; j++) {
		sum1 += f(getXj(a, h, j));
	}
	sum1 *= 2;

	for (int j = 0; j <= n-1; j++) {
		sum2 += f((getXj(a, h, j) + getXj(a, h, j+1))/2);
	}
	sum2 *= 4;

	return (b-a)/(6*n) * (f(a) + f(b) + sum1 + sum2);
}



double integrate(Function& f, double a, double b, double eps) {
	return shortenedSimpsonIntegral(f, a, b, 5, eps);
}



