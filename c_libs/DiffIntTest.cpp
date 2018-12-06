//
// Created by Kai Stanitzok on 2018-12-04.
//
#include <stdio.h>
#include <math.h>
#include "Function.h"
#include "Differentiator.h"
#include "Integrator.h"
#include "CUnit.h"

#define EPS 1.E-8


int difSinTest(int argc, char** argv) {
    Function f = Function(sin);
    for(double i = 0; i <= 2; i += 0.5) {
        assertEqualsF(differentiate(f,i,EPS), cos(i), EPS);
    }
    return 0;
}

int difExpTest(int argc, char** argv) {
    Function f = Function(exp);
    for(double i = 0; i <= 2; i += 0.5) {
       assertEqualsF(differentiate(f,i,EPS), exp(i), EPS);
    }
    return 0;

}

int difSqrtTest(int argc, char** argv) {
    Function f = Function(sqrt);
    for(double i = 1.0; i <= 2; i += 0.5) {
        assertEqualsF(differentiate(f,i,EPS), 1/(2*sqrt(i)), EPS);
    }
    return 0;

}

int integrateSinTest(int argc, char** argv) {
    double results[] = { 0, 0.4596976941318603, 1.416146836547142, 1.989992496600446, 1.653643620863612};
    Function f = Function(sin);
    for(int i = 0; i <= 4; i += 1) {
        assertEqualsF(integrate(f,0,i,EPS), results[i], EPS);
    }
    return 0;
}

int integrateExpTest(int argc, char **argv) {
    double res[] = {0, 1.718281828459045, 6.38905609893065, 19.08553692318767, 53.5981500509};
    int counter = 0;

    Function f = Function(exp);

    for(int i = 0; i <= 4; i += 1) {
        assertEqualsF(integrate(f, 0, i, EPS),res[i],EPS);
    }
    return 0;
}

int integrateSqrtTest(int argc, char** argv) {
    double dy[4];
    int counter = 0;

    Function f = Function(sqrt);

    for(double i = 1.; i <= 4; i += 1.) {
        dy[counter] = integrate(f,i,i+1.,EPS);
        counter++;
    }

    assertEqualsF(dy[0], (double)1.21895141649746, EPS);
    assertEqualsF(dy[1], (double)1.57848353197363, EPS);
    assertEqualsF(dy[2], (double)1.86923171819558, EPS);
    assertEqualsF(dy[3], (double)2.12022659166597, EPS);

    return 0;
}



DECLARE_TEST(difSin)
DECLARE_TEST(difExp)
DECLARE_TEST(difSqrt)

DECLARE_TEST(integrateSin)
DECLARE_TEST(integrateExp)
DECLARE_TEST(integrateSqrt)

BEG_SUITE(suite)
                ADD_TEST(difSin),
                ADD_TEST(difExp),
                ADD_TEST(difSqrt),
                ADD_TEST(integrateSin),
                ADD_TEST(integrateExp),
                ADD_TEST(integrateSqrt)
END_SUITE(suite)

RUN_SUITE(suite)