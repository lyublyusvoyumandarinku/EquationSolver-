#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED




enum Roots {
    ABSENCE_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS = -1
};



/**ASSERT
*@param logical expression
@brief
*/
#define ASSERT(cond) \
    if (cond) printf("Error in the expression (%s) in line %d ", #cond, __LINE__);  \
    //else printf("OK! ");

void assert_isfinite(double x);

int mode();

const int INF = -1;
const double EPS  = 1e-4;

int eq_0(double a);
int eq(double a, double b);

int square_equation(double a, double b, double c, double *x1, double *x2);
int linear_equation(double b, double c, double *x1);


void input(double *a, double *b, double *c);
void pretty_input();

void file_input(double *a, double *b, double *c);

void file_data();


void solve_and_output(double a, double b, double c);

#endif // FUNC_H_INCLUDED
