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


/**assert_isfinite
*@brief checks the number for its finiteness
*/
void assert_isfinite(double x);

/**mode
*@brief offers the user to choose where to get the data from
*/
int mode();

const int INF = -1;
const double EPS  = 1e-4;

/** eq
Compares fractional numbers
@param a,b compared numbers
@return equal numbers or not
*/
int eq(double a, double b);

/**eq_0
Compares fractional number
@param a compared with zero number
@return equal number zero or not
*/
int eq_0(double a);


/**square_equation
solves the quadratic equation
*\param a,b,c Coefficients of the equation
*\param *x1,*x2 References to variables containing the roots of the equation
*\return number of solutions
*/
int square_equation(double a, double b, double c, double *x1, double *x2);


/**linear_equation
*@brief Solves the linear equation
*@param a,b - Coefficients of the equation
*@param *x1 Reference to variable containing the root of the equation
*@return number of solutions
*/
int linear_equation(double b, double c, double *x1);


/**input
*@brief reads data from the console and writes it to variables at their address
 when errors occur, it issues a message
@param *a,*b,*c - variable addresses
*/
void input(double *a, double *b, double *c);


/**auxiliary input function*/
void pretty_input();


/**file_input
*@brief reads data from a file and writes it to variables at their address
*@param *a,*b,*c - variable addresses
*@param *fp - pointer to the file
*/
int file_input(double *a, double *b, double *c);


/**file_data
*@brief provides work with data in a file
*/
int file_data();



/**solve_and_output
*@brief the function starts solving the
  equation and displays the result of its work on the screen
*@param *a,*b,*c - variables ( Coefficients of the equation)

  */
void solve_and_output(double a, double b, double c);


#endif // FUNC_H_INCLUDED
