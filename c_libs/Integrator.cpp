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
	if (step > maxSteps)  {
		const char *error = "no convergence";
		throw error;
	}
	double differenceAbsolute = fabs(resNew-resOld);
	/*
	 * absolute error margin divided by the actual result:
	 * assuming that an average value of resNew and resOld is the actual result
	 */
	if(eps > differenceAbsolute/((resNew+resOld)/2)) return true;
	return eps > differenceAbsolute;
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
				if (j!=0) sum1 += f(a + h * j);
				sum2 += f(((a + h * j) + (a + h * (j+1)))/2);
			}
			// "rule of simpson" integrale, shortened
			resNew = (h/6) * (fa + fb + 2 * sum1 + 4*  sum2);

		} while(!convergenceIntegrator(resOld, resNew, ++counter, eps));
		return resNew;
	} catch (const char* error) {
		throw error;
	}
}