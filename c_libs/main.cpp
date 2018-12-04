#include <iostream>
#include "Function.h"
#include "Differentiator.h"
#include "Integrator.h"
#include "CUnit.h"
#include "math.h"
//#include "DiffIntTest.cpp"

using namespace std;

double xSquare(double x) {
    return pow(x,2);
}

double xSquareRoot(double x) {
    return pow(x,2);
}

double myfunction(double x) {
    return sin(x);
}


int main( int argc, const char* argv[] ) {
    srand((unsigned)time(0));
    Function f = Function(&myfunction, "square");
    double result = differentiate(f,0.1,1E-8);
    cout << result;
}
