#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "func.h"
#include "test.h"

/** eq
Compares fractional numbers
\param a,b compared numbers
\return equal numbers or not
*/
int eq(double a, double b){
    return fabs(a - b) < EPS;
}


/**eq_0
Compares fractional number
\param a compared with zero number
\return equal number zero or not
*/
int eq_0(double a){
    return fabs(a-0) < EPS;
}


/**square_equation
solves the quadratic equation
*\param a,b,c Coefficients of the equation
*\param *x1,*x2 References to variables containing the roots of the equation
*\return number of solutions
*/
int square_equation(double a, double b, double c, double *x1, double *x2){

    ASSERT(x1 == NULL);
    ASSERT(x2 == NULL);

    ASSERT(!(isfinite(a) && isfinite(b) && isfinite(c)));

    if (eq_0(a)) {
        int ans = linear_equation(b, c, x1);
        if (ans == 1) *x2 = *x1;
        return ans;
    }

    else{
        double d = b*b - 4*a*c;
        if (eq_0(d)) {
            *x1 = *x2 = -b / (2*a);
             return 1;
        }

        else if (d < 0) return 0;

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

    ASSERT(x1 == NULL);
    ASSERT(isfinite(b) && isfinite(c));

    if (eq_0(b) && eq_0(c))  return INF;

    if (eq_0(b) && !eq_0(c)) return 0;

    else *x1 = (-c) / b; return 1;
}


/**input
*\param *a,*b,*c - variable addresses
*/
void input(double *a, double *b, double *c) {

    ASSERT(a == NULL);
    ASSERT(b == NULL);
    ASSERT(c == NULL);

    printf("HELLO!\nEnter the coefficients of the equation (a, b, c): ");

    int n = scanf("%lf %lf %lf", a, b, c);
    while(1){
        if (n != 3) {
            pretty_input();
            n = scanf("%lf %lf %lf", a, b, c);
        }
        else{
            ASSERT(isfinite(*a) && isfinite(*b) && isfinite(*c));
            break;
        }
    }

 }

void pretty_input(){
    while (getchar()!='\n');
    fprintf(stderr, "ERROR!\nEnter the coefficients of the equation again:");
}



void output(double a, double b, double c) {
    double x1 = NAN, x2 = NAN;
    printf("The equation is: (%.2lg)*x^2  + (%.2lg)*x + (%.2lg) = 0\n", a, b, c);
    switch(square_equation(a, b, c, &x1, &x2)){
        case 0:   printf("This equation doesn't have roots\n");                          break;
        case 1:   printf("This equation has 1 root: x = %.2lf\n", x1);                   break;
        case 2:   printf("This equation has 2 roots: x1 = %.2lf, x2 = %.2lf\n", x1, x2); break;
        case INF: printf("This equation have infinite roots\n");                         break;
        default:  abort();
    }

    printf("\nChecking: ");
    test_once(a, b, c, 1);
}
