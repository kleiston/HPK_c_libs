/*
 * Differentiator.c
 *
 *  Created on: Dec 3, 2018
 *      Author: Kai
 */

#include "Differentiator.h"
#include "math.h"
#include <stdexcept>



double difference = 0;
bool convergence(double diffOld, double diffNew, double eps) {
	if(diffOld == 0|| diffNew == 0) {
		return false;
	}
	double differenceNew = fabs(diffOld) - fabs(diffNew);
	if(difference != 0 && difference < differenceNew) {
		throw std::invalid_argument( "Function does not converge" );
	}
	difference = differenceNew;

 return difference < eps;
}

double diff(Function& f, double x, double h) {
double fXPLUSH = f(x+h);
double fXMINUS = f(x - h);

  return (fXPLUSH - fXMINUS)/ (2*h);
}

double differentiate(Function& f, double x, double err) {
	double diffOld = 0;
	double diffNew = 0;
	try {
		double h = 0.1;
			double fOld = diff(f,x,h);
			do {
				diffOld = diffNew;
				diffNew = (16*fOld- (fOld= diff(f,x,2*h)))/15;
				h /= 2;
			} while(!convergence(diffOld, diffNew, err));
	} catch(char* exception) {
		throw std::invalid_argument( exception );
	}
return diffNew;
}





