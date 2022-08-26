#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "func.h"
#include "test.h"


int mode() {

    printf("where will the data be entered from?\n1 - console\n2 - file\n");

    int mode = NAN;

    while ( ((scanf("%d", &mode)) != 1) && (mode != 1) && (mode != 2)  )
        printf("Error!");

    return mode;
}


int eq(double a, double b) {
    return fabs(a - b) < EPS;
}


int eq_0(double a) {
    return eq(a,0);
}



int square_equation(double a, double b, double c, double *x1, double *x2) {


    ASSERT(x1 == NULL);
    ASSERT(x2 == NULL);

    assert_isfinite(a);
    assert_isfinite(b);
    assert_isfinite(c);

    if (eq_0(a)) {
        int ans = linear_equation(b, c, x1);
        if (ans == 1)
            *x2 = *x1;
        return ans;
    }

    double d = b*b - 4*a*c;
    if (eq_0(d)) {
        *x1 = *x2 = -b / (2*a);
         return ONE_ROOT;
    }

    if (d < 0)
        return ABSENCE_ROOTS;

    double sd = sqrt(d);
    *x1 = -(b + sd) / (2*a);
    *x2 = -(b - sd) / (2*a);
    return TWO_ROOTS;
}



int linear_equation(double b, double c, double *x1) {

    ASSERT(x1 == NULL);

    assert_isfinite(b);
    assert_isfinite(c);


    if (eq_0(b))
        if (eq_0(c))
            return INFINITE_ROOTS;

        return ABSENCE_ROOTS;


    *x1 = (-c) / b;
    return ONE_ROOT;


}



void input(double *a, double *b, double *c) {

    ASSERT(a == NULL);
    ASSERT(b == NULL);
    ASSERT(c == NULL);

    printf("\nDATA FROM THE CONSOLE\n");
    printf("Enter the coefficients of the equation (a, b, c): ");

    int n = scanf("%lf %lf %lf", a, b, c);
    while(1) {
        if (n != 3) {
            pretty_input();
            n = scanf("%lf %lf %lf", a, b, c);
        }
        else {
            break;
        }
    }

 }


void pretty_input() {
    while (getchar()!='\n');
    fprintf(stderr, "ERROR!\nEnter the coefficients of the equation again:");
}



int file_input(double *a, double *b, double *c, FILE *fp) {

    int n = fscanf(fp, "%lf %lf %lf", a, b, c);
    if (n != 3) {
        printf("ERROR! Enter the coefficients of the equation in file again!/n");
        return 0;
    }
    return 1;
}



int file_data() {

    printf("\nDATA FROM THE FILE\n");
    char file_name[] = "data_imput.txt";
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL){
        printf("error! file hasn't opened");
        return 0;
    }

    double a = NAN, b = NAN, c = NAN;
    while(!feof(fp)){
        double a = NAN, b = NAN, c = NAN;
        if (!(file_input(&a, &b, &c, fp))) {
            printf("ERROR!\n");
            return 0;
        }
        solve_and_output(a, b, c);
    }

    fclose(fp);
}


void assert_isfinite(double x) {
    ASSERT(!(isfinite(x)));
}


void solve_and_output(double a, double b, double c) {

    assert_isfinite(a);
    assert_isfinite(b);
    assert_isfinite(c);

    double x1 = NAN, x2 = NAN;
    printf("The equation is: (%.2lg)*x^2  + (%.2lg)*x + (%.2lg) = 0\n", a, b, c);

    switch(square_equation(a, b, c, &x1, &x2)){
        case 0:
            printf("This equation doesn't have roots\n");
            break;
        case 1:
            printf("This equation has 1 root: x = %.2lf\n", x1);
            break;
        case 2:
            printf("This equation has 2 roots: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
            break;
        case INF:
            printf("This equation have infinite roots\n");
            break;
        default:
            printf("ERROR\n");
            abort();
    }

    printf("Checking: ");
    test_once(a, b, c, 100);
    printf("\n");
}





