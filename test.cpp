#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "test.h"
#include "func.h"


double rand_num(double step) {
    return -step + (double)(rand()) / RAND_MAX * step * 2;
}



void test_once(double a, double b, double c, int test_number) {

    assert_isfinite(a);
    assert_isfinite(b);
    assert_isfinite(c);

    printf("Test %2d, results of test: ", test_number);

    double y1 = 0, y2 = 0;
    int ok = 0;

    int n_roots = square_equation(a, b, c, &y1, &y2);

    if (n_roots == 1) y2 = y1;

    if (n_roots > 0){
        int p1 = (eq_0(a*y1*y1 + b*y1 + c));
        int p2 = (eq_0(a*y2*y2 + b*y2 + c));

        if (p1 * p2) ok = 1;

        if (p1 == 0)
            printf("ERROR! a=%.2lf b=%.2lf c=%.2lf y1=%.2lf", a, b, c, y1);
        if (p2 == 0)
            printf("ERROR! a=%.2lf b=%.2lf c=%.2lf y2=%.2lf", a, b, c, y2);
    }

    else  ok = 1;
    if (ok == 1){
        printf("All is OK!");
        if (n_roots > 0)    printf(" Count of roots: %d  ", n_roots);

        if (n_roots == INF)
            printf(" Infinite number of roots for a = %.2lg, b = %.2lg, c = %.2lg", a,     b,     c);
        if (n_roots == 0)
            printf(" No roots for a = %.2lg, b = %.2lg, c = %.2lg",                 a,     b,     c);
        if (n_roots == 1)
            printf(" (%.2lg)*(%.2lg)^2 + (%.2lg)*(%.2lg) + (%.2lg) = 0",            a, y1, b, y1, c);
        if (n_roots == 2) {
            printf(" (%.2lg)*(%.2lg)^2 + (%.2lg)*(%.2lg) + (%.2lg) = 0;  ",         a, y1, b, y1, c);
            printf(" (%.2lf)*(%.2lf)^2 + (%.2lf)*(%.2lf) + (%.2lf) = 0",            a, y2, b, y2, c); }
    }

    printf("\n");
}


void test_once_with_roots(double a, double b, double c, int test_number, int n_roots_true) {

    assert_isfinite(a);
    assert_isfinite(b);
    assert_isfinite(c);


    double p1 = 0, p2 = 0;
    int n_roots = square_equation(a, b, c, &p1, &p2);

    if (n_roots != n_roots_true)
        printf("ERROR! by decision: %d;  in fact: %d \n", n_roots, n_roots_true);

    else
        test_once(a, b, c, test_number);
}



void testing() {

    int number_test = 1;

    double atest = rand_num(20);
    double btest = rand_num(20);
    double ctest = rand_num(20);


    test_once_with_roots(0,   0,  0,  number_test++, INFINITE_ROOTS);
    test_once_with_roots(1,   2, -3,  number_test++,      TWO_ROOTS);
    test_once_with_roots(-1,  4,  3,  number_test++,      TWO_ROOTS);
    test_once_with_roots(17, 18, 19,  number_test++,       ZERO_ROOT);


    test_once(0,     0,     0,     number_test++);

    test_once(0,     btest, ctest, number_test++);
    test_once(atest, 0,     ctest, number_test++);
    test_once(atest, btest, 0,     number_test++);

    test_once(atest, 0,     0,     number_test++);
    test_once(0,     btest, 0,     number_test++);
    test_once(0,     0,     ctest, number_test++);

    for (int i = number_test; i < number_test + 5; i++){

        atest = rand_num(20);
        btest = rand_num(20);
        ctest = rand_num(20);

        test_once(atest, btest, ctest, i);
    }

    printf("\n");
}
