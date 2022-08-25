#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <TXLib.h>
#include <locale.h>
#include "func.h"


/**ASSERT
*@param logical expression
@brief
*/
#define ASSERT(cond) \
    if (!(cond)) printf("Error in the expression (%s) in line %d ", #cond, __LINE__);  \
    else printf("OK! ");


int main(){
    srand(time(NULL));
    double a = NAN, b = NAN, c = NAN;
    double x1 = 0, x2 = 0;

    testing();
    printf("Enter the coefficients of the equation: ");

    int n = scanf("%lf %lf %lf", &a, &b, &c);
    while(1){
        if (n != 3 && getchar()!='\n') {
            printf("ERROR!\n");
            fflush (stdout);
            n = scanf("%lf %lf %lf", &a, &b, &c);
        }
        else break;
    }

    ASSERT(isfinite(a) && isfinite(b) && isfinite(c));
    printf("The equation is: (%.2lg)*x^2  + (%.2lg)*x + (%.2lg) = 0\n", a, b, c);


    switch(square_equation(a, b, c, &x1, &x2)){
    case 0:   printf("this equation doesn't have roots\n"); break;
    case 1:   printf("this equation has 1 root: x = %.2lf\n", x1); break;
    case 2:   printf("this equation has 2 roots: x1 = %.2lf, x2 = %.2lf\n", x1, x2); break;
    case INF: printf("this equation have infinite roots\n"); break;
    default:  printf("ERROR!");
    }
    printf("\nChecking"); test_once(a, b, c, 0);

}
