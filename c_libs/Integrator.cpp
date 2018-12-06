/*
 * Integrator.c
 *
 *  Created on: Dec 3, 2018
 *      Author: Kai
 */
#include "Integrator.h"
#include <math.h>

int maxSteps = 12;
bool convergenceIntegrator(double resOld, double resNew, int step, double eps) {
	double differenceIntegrated = fabs(resOld-resNew);
	if (step > maxSteps) {
		const char* error = "no convergence";
		throw error;
	}
	if(fabs((resOld-resNew)/((resNew+resOld)/2)) < eps) return true;
	return eps > differenceIntegrated;
}

double integrate(Function& f, double a, double b, double eps) {
	try {
		int n = 1, counter = 0;
		double resOld, resNew, fa = f(a), fb = f(b), h, sum1, sum2;

		do {
			n *= 2;
			h = (b-a)/n;
			resOld = resNew;
			sum1 = 0;
			sum2 = 0;

			for (int j = 0; j < n; j++) {
				sum2 += f(((a + h * j) + (a + h * (j+1)))/2);
				if (j!=0) sum1 += f(a + h * j);;
			}

			resNew = (h/6) * (fa + fb + 2 * sum1 + 4*  sum2);

		} while(!convergenceIntegrator(resOld, resNew, ++counter, eps));
		return resNew;
	} catch (const char* error) {
		throw error;
	}
}