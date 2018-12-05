/*
 * Integrator.c
 *
 *  Created on: Dec 3, 2018
 *      Author: Kai
 */
#include "Integrator.h"
#include <math.h>

double getXj(double a, double h, double j) {
	return a + (h * j);
}

double shortenedSimpsonIntegral(Function& f, double a, double b, double n) {
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

double difference = 0;

bool convergence(double oldRes, double newRes, double eps) {
	double differenceNew = fabs(oldRes-newRes);
	if (difference != 0 && difference < differenceNew) throw "no convergence";
	difference = differenceNew;
	return eps > difference;
}

double integrate(Function& f, double a, double b, double eps) {
	int n = 256;
	double x1 = shortenedSimpsonIntegral(f, a, b, n);
	double x2 = 0;
	do {
		if (x2 != 0) x1 = x2;
		n/=2;
		x2 = shortenedSimpsonIntegral(f, a, b, n);
	} while (!convergence(x1, x2, eps));
}
