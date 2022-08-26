#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <TXLib.h>
#include <locale.h>

#include "func.h"
#include "test.h"



int main(int argc, const char* argv[]) {

    srand(time(NULL));


    if (argc > 1) {
        char tests[] = "test";

        if (!(strcmp (tests, argv[1]))) {
            testing();
            return 0;
        }
    }


    if (mode() == 1) {

        double a = NAN, b = NAN, c = NAN;
        input( &a, &b, &c);

        solve_and_output(a, b, c);
    }

    else
        file_data();


}


