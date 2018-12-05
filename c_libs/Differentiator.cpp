/*
 * Differentiator.c
 *
 *  Created on: Dec 3, 2018
 *      Author: Kai
 */

#include "Differentiator.h"
#include "math.h"


int maxIterations = 12;

bool convergence(double resultOld, double resultNew, double eps, double count) {
	double differenceNew = fabs(resultOld - resultNew);
	if(count > maxIterations) {
		const char* error = "no convergence";
		throw error;
	}
    return differenceNew < eps;
}

double delta(Function& f, double x, double h) {
    double fXPLUSH = f(x + h);
    double fXMINUS = f(x - h);
    return (fXPLUSH - fXMINUS);
}

double differentiate(Function& f, double x, double err) {
    double delta2H = 0; double deltaH = 0;
	double dFNew = 0; double dFOld = 0;
	double rOld = 0; double rNew = 0;
    double h = 0.1; int count = 0;
    try {
			do {
                dFOld = dFNew;
                delta2H =  delta(f, x, h);
				dFNew = ((8*delta2H)-deltaH)/(12*h);
				deltaH = delta2H;
				rOld = rNew;
				rNew = (16*dFNew - dFOld)/15;
                h /= 2;
            } while(!convergence(rOld, rNew, err, count++));
	} catch(const char* exception) {
		throw exception;
	}
    return rNew;
}


