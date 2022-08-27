#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "include/add.h"
#include "include/mul.h"

int main(int argc, char **argv) {
    if (argc == 2) {
        if (argv[1][1] == 'h') {
            printf(
                "Basic usage: ./bin/app [-f or -i] [-a or -m] a b\n"
                "  -i or -f: specifies if passing int or float\n"
                "  -a or -m: specifies if adding or multiplying numbers\n"
                "  a and b: two numbers\n"
                );
        }
        return 0;
    }

    assert(argc == 5);

    if (argv[1][1] == 'f') {
        float a = atof(argv[3]);
        float b = atof(argv[4]);
        if (argv[2][1] == 'a') {
            printf("%.1f + %.1f = %.1f\n", a, b, add_float(a, b));
        } else if (argv[2][1] == 'm') {
            printf("%.1f * %.1f = %.1f\n", a, b, mul_float(a, b));
        }
    } else if (argv[1][1] == 'i') {
        int a = atoi(argv[3]);
        int b = atoi(argv[4]);
        if (argv[2][1] == 'a') {
            printf("%d + %d = %d\n", a, b, add_int(a, b));
        } else if (argv[2][1] == 'm') {
            printf("%d * %d = %d\n", a, b, mul_int(a, b));
        }
    }

    return 0;
}