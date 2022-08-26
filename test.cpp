#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "test.h"
#include "func.h"

/**rand_num
*@param step
*@return a random fractional number in the range [-step; step]
*/
double rand_num(double step){
    double num = -step + (double)(rand()) / RAND_MAX * step * 2;
    return num;
}


/**test_once
*@brief tests the program once with random input data
*@param a,b, c - Coefficients of the equation
*/
void test_once(double a, double b, double c, int i){

    assert_isfinite(a);
    assert_isfinite(b);
    assert_isfinite(c);

    printf("Test %2.d, results of test: ", i);

    double y1 = 0, y2 = 0;
    int ok = 0;

    int n_roots = square_equation(a, b, c, &y1, &y2);

    if (n_roots == 1) y2 = y1;

    if (n_roots > 0){
        int p1 = (eq_0(a*y1*y1 + b*y1 + c));
        int p2 = (eq_0(a*y2*y2 + b*y2 + c));

        if (p1 * p2) ok = 1;

        if (p1 == 0)  printf("ERROR! a=%.2lf b=%.2lf c=%.2lf y1=%.2lf", a, b, c, y1);
        if (p2 == 0)  printf("ERROR! a=%.2lf b=%.2lf c=%.2lf y2=%.2lf", a, b, c, y2);
    }

    else  ok = 1;
    if (ok == 1){
        printf("All is OK!");
        if (n_roots > 0)    printf(" Count of roots: %d  ", n_roots);

        if (n_roots == INF)   printf(" Infinite number of roots for a = %.2lg, b = %.2lg, c = %.2lg", a,     b,     c);
        if (n_roots == 0)     printf(" No roots for a = %.2lg, b = %.2lg, c = %.2lg",                 a,     b,     c);
        if (n_roots == 1)     printf(" (%.2lg)*(%.2lg)^2 + (%.2lg)*(%.2lg) + (%.2lg) = 0",            a, y1, b, y1, c);
        if (n_roots == 2){    printf(" (%.2lg)*(%.2lg)^2 + (%.2lg)*(%.2lg) + (%.2lg) = 0;  ",         a, y1, b, y1, c);
                              printf(" (%.2lf)*(%.2lf)^2 + (%.2lf)*(%.2lf) + (%.2lf) = 0",            a, y2, b, y2, c); }
    }

    printf("\n");
}


/**testing
tests the program once with random input data*/
void testing(){

    int M = 1;

    double atest = rand_num(20);
    double btest = rand_num(20);
    double ctest = rand_num(20);

    test_once(0,     0,     0,     M++);

    test_once(0,     btest, ctest, M++);
    test_once(atest, 0,     ctest, M++);
    test_once(atest, btest, 0,     M++);

    test_once(atest, 0,     0,     M++);
    test_once(0,     btest, 0,     M++);
    test_once(0,     0,     ctest, M++);

    for (int i = M; i < M+5; i++){

        atest = rand_num(20);
        btest = rand_num(20);
        ctest = rand_num(20);

        test_once(atest, btest, ctest, i);
    }

    printf("\n");
}
