#include <stdint.h>
#include <math.h>

#include "quadratic.h"

uint8_t solve_quadratic(const quad_coeffs_t coeffs, quad_roots_t *roots){
  enum quadratic_status status = QUAD_SUCCESS;
  if (coeffs.a == 0.0) {
    status = QUAD_ERROR_a_equals_0;
  }
  double b2m4ac = coeffs.b * coeffs.b - 4.0 * coeffs.a * coeffs.c;
  if (b2m4ac < 0.0) {
    status = QUAD_ERROR_imaginary_roots;
  }
  if (QUAD_SUCCESS == status) {
    double sqrt_term = sqrt(b2m4ac);
    double denom = 2.0 * coeffs.a;
    roots->root_1 = (-coeffs.b + sqrt_term) / denom;
    roots->root_2 = (-coeffs.b - sqrt_term) / denom;
  }
  return status;
}
