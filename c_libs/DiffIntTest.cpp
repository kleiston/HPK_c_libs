//
// Created by Kai Stanitzok on 2018-12-04.
//

/*
 * DifferentiatorTest.cpp
 *
 *  Created on: 28 Nov 2018
 *      Author: Till
 */
#include <stdio.h>
#include <math.h>
#include "Function.h"
#include "Differentiator.h"
#include "Integrator.h"
#include "CUnit.h"

#define EPS 1.E-4

//CUnitTestSuite suite;

int difSinTest(int argc, char** argv) {
    Function f = Function(sin);
    for(double i = 0; i <= 2; i += 0.5) {
        assertEqualsF(differentiate(f,i,EPS), cos(i), EPS);
    }
    return 0;
}

int difExpTest(int argc, char** argv) {
    double dy[5];
    int counter = 0;

    Function f = Function(exp);

    for(double i = 0; i <= 2; i += 0.5) {
        dy[counter] = differentiate(f,i,EPS);
        counter++;
    }

    assertEqualsF(dy[0], (double)1.0, EPS);
    assertEqualsF(dy[1], (double)1.64872, EPS);
    assertEqualsF(dy[2], (double)2.71828, EPS);
    assertEqualsF(dy[3], (double)4.48169, EPS);
    assertEqualsF(dy[4], (double)7.38906, EPS);

    return 0;

}

int difSqrtTest(int argc, char** argv) {
    double dy[3];
    int counter = 0;

    Function f = Function(sqrt);

    for(double i = 1.0; i <= 2; i += 0.5) {
        dy[counter] = differentiate(f,i,EPS);
        counter++;
    }
    assertEqualsF(dy[0], (double)0.5, EPS);
    assertEqualsF(dy[1], (double)0.408248, EPS);
    assertEqualsF(dy[2], (double)1/(2*sqrt(2)), EPS);

    return 0;

}

int integrateSinTest(int argc, char** argv) {
    double results[] = { 0.45970, 0.95645, 0.57385, -0.33635, -0.93731};
    Function f = Function(sin);
    for(int i = 0; i <= 4; i += 1) {
        double res = integrate(f,i,i+1,EPS);
        assertEqualsF(res, results[i], EPS);
    }
    return 0;
}

int integradeExpTest(int argc, char** argv) {
    double dy[5];
    int counter = 0;

    Function f = Function(exp);

    for(double i = 0; i <= 4; i += 1.) {
        dy[counter] = integrate(f,i,i+1.,EPS);
        counter++;
    }

    assertEqualsF(dy[0], (double)1.71828182845905, EPS);
    assertEqualsF(dy[1], (double)4.67077427047160, EPS);
    assertEqualsF(dy[2], (double)12.6964808242570, EPS);
    assertEqualsF(dy[3], (double)34.5126131099566, EPS);
    assertEqualsF(dy[4], (double)93.8150090694324, EPS);

    return 0;
}

int integradeSqrtTest(int argc, char** argv) {
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
DECLARE_TEST(integradeExp)
DECLARE_TEST(integradeSqrt)

BEG_SUITE(suite)
                ADD_TEST(difSin),
                ADD_TEST(difExp),
                ADD_TEST(difSqrt),
                ADD_TEST(integrateSin),
                ADD_TEST(integradeExp),
                ADD_TEST(integradeSqrt)
END_SUITE(suite)

RUN_SUITE(suite)