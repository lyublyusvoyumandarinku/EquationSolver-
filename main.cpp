#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <TXLib.h>
#include <locale.h>

#include "func.h"
#include "test.h"

//#define TESTS

int main(){
    srand(time(NULL));

    #ifdef TESTS
        testing();
    #endif


    double a = NAN, b = NAN, c = NAN;

    input( &a, &b, &c);

    output(a, b, c);


}


//днаюбхрэ времхе хг тюикю
