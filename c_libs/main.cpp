#include <iostream>
#include "Function.h"
#include "Differentiator.h"
#include "Integrator.h"
#include "CUnit.h"
#include "math.h"

using namespace std;

double xSquare(double x) {
return 2*pow(x,2);
}

int main( int argc, const char* argv[] )
{
Function f = Function(&xSquare, "square");
double result = integrate(f, 2, 4, 1E-9);
cout << result;
}
