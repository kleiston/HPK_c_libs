#include <iostream>
#include "Function.h"
#include "Differentiator.h"
#include "Integrator.h"
#include "CUnit.h"
#include "math.h"

using namespace std;

double xSquare(double x) {
    return pow(x,2);
}

double xSquareRoot(double x) {
    return pow(x,2);
}

int main( int argc, const char* argv[] ) {
    Function f = Function(&xSquare, "square");
    double result = differentiate(f,2, 1E-9);
    cout << result;
}
