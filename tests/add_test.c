#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>

#include "../include/add.h"

static void add_float_test(void **state) {
    assert_float_equal(5.5, add_float(2.3, 3.2), 0.1);
}

static void add_int_test(void **state) {
    assert_int_equal(5, add_int(2, 3));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(add_float_test),
        cmocka_unit_test(add_int_test),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}