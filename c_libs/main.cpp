#include <iostream>
#include "Function.h"
#include "Differentiator.h"
#include "Integrator.h"
#include "CUnit.h"
#include "math.h"
#include "DiffIntTest.cpp"

#define EPS 1.E-8


using namespace std;

int counter = 0;

double xSquare(double x) {
    counter++;
    return pow(x,2);
}

double xExp(double x) {
    counter++;
    return exp(x);
}

double xSin(double x) {
    counter++;
    return sin(x);
}

double xTan(double x) {
    counter++;
    return tan(x);
}


void testFunction(Function &fct, double incrementCount, double incrementMax) {
    int diffCount = 0;
    counter = 0;
    printf("Testing Function: \"%s\"\n",fct.name());
    printf("---------+------------------+----------------+------------------+-------+-----\n");
    printf("x\t\t |f(x)=%s(x)\t\t| f’(x)\t\t\t | F(x)\t\t\t\t|#f’\t|#int\n", fct.name());
    printf("---------+------------------+----------------+------------------+-------+-----\n");
    for(double x = 0; x <= incrementMax; x += incrementCount ) {
        diffCount = 0;
        printf("%-2.4f\t\t", x);
        printf("%-2.10f\t", fct(x));
        counter = 0;
        printf("  %-2.10f", differentiate(fct,x,EPS));
        diffCount = counter;
        counter = 0;
        printf(" \t\t%-2.10f", integrate(fct,0,x,EPS));
        printf("\t\t%d\t\t%d", diffCount, counter);
        printf("\n");
    }
    printf("\n");
}


double test(double x) {
    return x*sin(1/x);
}


/*
int main( int argc, const char* argv[] ) {
    Function functions[] = {Function(xSquare, "sqr"), Function(xExp, "exp"), Function(xSin, "sin"),
                            Function(xTan, "tan")};

    double increments[4][2] = {{0.25,1}, {1,10}, {0.3927,3.1416}, {0.1963,0.7854}};

    Function fct = Function(test);

    for(int i = 0; i< 4; i++) {
        testFunction(functions[i],increments[i][0], increments[i][1]);

    }
}
 */