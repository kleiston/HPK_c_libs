/*
 * Differentiator.c
 *
 *  Created on: Dec 3, 2018
 *      Author: Kai
 */

#include "Differentiator.h"
#include "math.h"

double difference = 0.0;
bool convergence(double diffOld, double diffNew, double eps) {
	double differenceNew = fabs(diffOld - diffNew);
	if(difference != 0.0 && difference < differenceNew) {
		const char* error = "no convergence";
		throw error;
	}
	difference = differenceNew;

 return difference < eps;
}

double diff(Function& f, double x, double h) {
double fXPLUSH = f(x + h);
double fXMINUS = f(x - h);

  return (fXPLUSH - fXMINUS)/ (2*h);
}

double differentiate(Function& f, double x, double err) {
	double differentiatedOld = 0;
	double differentiatedNew = 0;
	try {
		double h = 0.1;
			double fOld = diff(f,x,h);
			do {
				differentiatedOld = differentiatedNew;
				differentiatedNew = ( 16 * fOld - (fOld = diff(f,x,2*h)) ) /15;
				h /= 2;
			} while(!convergence(differentiatedOld, differentiatedNew, err));
	} catch(const char* exception) {
		difference = 0;
		throw exception;
	}
	difference = 0;
    return differentiatedNew;
}





