#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

/**test_once
*@brief tests the program once with random input data
*@param a,b,c - Coefficients of the equation
*/
void test_once(double a, double b, double c, int i);

/**testing
tests the program once with random input data*/
void testing();

void test_once_with_roots(double a, double b, double c, int test_number, int n_roots_true);

/**rand_num
*@param step
*@return a random fractional number in the range [-step; step]
*/
double rand_num(double step);

#endif // TEST_H_INCLUDED
