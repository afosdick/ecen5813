#include <math.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "quadratic.h"

const double quadratic_epsilon = 1.0e-16;

void test_a_equal_0(void **state)
{
  quad_coeffs_t coeffs;
  coeffs.a = 0.0;
  coeffs.b = 1.0;
  coeffs.c = 1.0;
  quad_roots_t roots;
  enum quadratic_status status = solve_quadratic(coeffs, &roots);
  assert_int_equal(status, QUAD_ERROR_a_equals_0);
}

void test_imaginary_roots(void **state)
{
  quad_coeffs_t coeffs;
  coeffs.a = 1.0;
  coeffs.b = 1.0;
  coeffs.c = 1.0;
  quad_roots_t roots;
  enum quadratic_status status = solve_quadratic(coeffs, &roots);
  assert_int_equal(status, QUAD_ERROR_imaginary_roots);
}

void test_complex_roots_skip(void **state)
{
  skip(); // complex roots have not been implemented yet.
  assert_int_equal(0, 1);
}

void test_complex_roots_xfail(void **state)
{
  // complex roots have not been implemented yet, expected failure
  quad_coeffs_t coeffs;
  coeffs.a = 1.0;
  coeffs.b = 1.0;
  coeffs.c = 1.0;
  quad_roots_t roots;
  enum quadratic_status status = solve_quadratic(coeffs, &roots);
  assert_int_not_equal(status, QUAD_SUCCESS);
}

void test_real_roots(void **state)
{
  quad_coeffs_t coeffs;
  coeffs.a = 2.0;
  coeffs.b = -3.0;
  coeffs.c = -2.0;
  quad_roots_t roots;
  enum quadratic_status status = solve_quadratic(coeffs, &roots);
  assert_int_equal(status, QUAD_SUCCESS);
  double expected_root_1 = 2.0;
  double expected_root_2 = -0.5;
  assert_true(fabs(roots.root_1 - expected_root_1) < quadratic_epsilon);
  assert_true(fabs(roots.root_2 - expected_root_2) < quadratic_epsilon);
}

int main(int argc, char **argv)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_a_equal_0),
    cmocka_unit_test(test_real_roots),
    cmocka_unit_test(test_imaginary_roots),
    cmocka_unit_test(test_complex_roots_skip),
    cmocka_unit_test(test_complex_roots_xfail),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
