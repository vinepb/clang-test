#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>

#include "../include/mul.h"

static void mul_float_test(void **state) {
    assert_float_equal(6.0, mul_float(2.0, 3.0), 0.1);
}

static void mul_int_test(void **state) {
    assert_int_equal(6, mul_int(2, 3));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(mul_float_test),
        cmocka_unit_test(mul_int_test),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
