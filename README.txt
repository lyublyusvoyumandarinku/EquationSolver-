GreatEquationSolver

This project is a program that allows the user to get a solution to a quadratic equation.
To run the program, the g++ compiler (MinGW, etc.) or any development environment
that supports the C language must be installed on the device. To run the project, you need to compile the project files with the extension .cpp
using the command line (for example, like this: g++ main.cpp func.cpp test.coo -o solve.exe where solve.exe - an executable file
that should then be run.
The program prompts the user to enter the coefficients of the equation (a, b, c). If the input is incorrect, the program
will point it out and offer to repeat it. After execution, it will give the result: the number of roots of the equation and
the roots themselves, if any, as well as the equation in standard form.
The program has built-in the ability to test on various input data (to start testing, you need to specify define TESTS on the command line).
If any test is not passed, the program outputs all the input and output data of the failed test.

There is no license, it is allowed to print, copy and use for non-commercial purposes.
Version: EquationSolver 1.0 (c) Kolyanchik 08.2022
