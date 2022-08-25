#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "func.h"


/** eq
Compares fractional numbers
\param a,b compared numbers
\return equal numbers or not
*/
int eq(double a, double b) {
    return fabs(a - b) < EPS;
}


/**eq_0
Compares fractional number
\param a compared with zero number
\return equal number zero or not
*/
int eq_0(double a) {
    return fabs(a-0) < EPS;
}


/**square_equation
solves the quadratic equation
*\param a,b,c Coefficients of the equation
*\param *x1,*x2 References to variables containing the roots of the equation
*\return number of solutions
*/
int square_equation(double a, double b, double c, double *x1, double *x2){

    if (eq_0(a)) {
        int ans = linear_equation(b, c, x1);
        if (ans == 1) x2 = x1;
        return ans;
    }

    else{
        double d = b*b - 4*a*c;
        if (d < 0) return 0;

        else if (eq_0(d)) {
            *x1 = *x2 = -b / (2*a);
             return 1;
        }
        else {
            double sd = sqrt(d);
            *x1 = -(b+sd) / (2*a);
            *x2 = -(b-sd) / (2*a);
            return 2;
        }

    }
}


/**linear_equation
*@brief Solves the linear equation
*@param a,b - Coefficients of the equation
*@param *x1 Reference to variable containing the root of the equation
*@return number of solutions
*/
int linear_equation(double b, double c, double *x1){
    if (eq_0(b) && eq_0(c))  return INF;

    if (eq_0(b) && !eq_0(c)) return 0;

    else *x1 = (-c) / b; return 1;
}


/**tests the program once with random input data
*@param a,b, c - Coefficients of the equation
*/
void test_once(double a, double b, double c, int i){
    printf("Test %2.d, results of test: ", i);

    double y1 = 0, y2 = 0;
    int ok = 0;
    int t = square_equation(a, b, c, &y1, &y2);

    if (t == 1) y2 = y1;
    if (t > 0){
        int p1 = (eq_0(a*y1*y1 + b*y1 + c));
        int p2 = (eq_0(a*y2*y2 + b*y2 + c));
        if (p1*p2) ok = 1;

        if (p1==0)  printf("ERROR! a=%.2lf b=%.2lf c=%.2lf y1=%.2lf", a, b, c, y1);
        if (p2==0)  printf("ERROR! a=%.2lf b=%.2lf c=%.2lf y2=%.2lf", a, b, c, y2);

    }
    else  ok = 1;
    if (ok==1){
        printf("All is OK!");
        if (t>0)    printf(" Count of roots: %d", t);

        if (t==INF)   printf(" Infinite number of roots for a = %.2lg, b = %.2lg, c = %.2lg", a,     b,     c);
        if (t==0)     printf(" No roots for a = %.2lg, b = %.2lg, c = %.2lg",                 a,     b,     c);
        if (t==1)     printf(" (%.2lg)*(%.2lg)^2 + (%.2lg)*(%.2lg) + (%.2lg) = 0",            a, y1, b, y1, c);
        if (t==2){    printf(" (%.2lg)*(%.2lg)^2 + (%.2lg)*(%.2lg) + (%.2lg) = 0;  ",         a, y1, b, y1, c);
                      printf(" (%.2lf)*(%.2lf)^2 + (%.2lf)*(%.2lf) + (%.2lf) = 0",            a, y2, b, y2, c); }
    }

    printf("\n");
}


/**tests the program once with random input data*/
void testing(){
    double atest = -20 + rand()%40;
    double btest = -20 + rand()%40;
    double ctest = -20 + rand()%40;
    test_once(0, 0, 0, 1);
    test_once(atest, btest, 0, 2);
    test_once(atest, 0, ctest, 3);
    test_once(0, btest, ctest, 4);
    test_once(atest, 0, 0, 5);
    test_once(0, btest, 0, 6);
    test_once(0, 0, ctest, 7);
    for (int i = 7; i < 17; i++){
        /*random input data*/
        atest = -20 + rand()%40;
        btest = -20 + rand()%40;
        ctest = -20 + rand()%40;
        test_once(atest, btest, ctest, i);
    }
    printf("\n");
}
