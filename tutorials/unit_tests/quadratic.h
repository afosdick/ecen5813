#ifndef CM_EXAMPLE_QUADRATIC_H
#define CM_EXAMPLE_QUADRATIC_H

#include <stdint.h>

enum quadratic_status {
  QUAD_ERROR_a_equals_0,
  QUAD_ERROR_imaginary_roots,
  QUAD_SUCCESS
};

struct quadratic_coefficients_t {
  // coefficients in a quadratic equation: a * x^2 + b * x + c = 0

  double a;
  double b;
  double c;
};

typedef struct quadratic_coefficients_t quad_coeffs_t;

struct quadratic_roots_t {
  double root_1;
  double root_2;
};

typedef struct quadratic_roots_t quad_roots_t;

/**
   quadratic()
   
   Solve the quadratic equation for x given set of coefficients:

   a * x^2 + b * x + c = 0

   params quad_coefficients
   params roots
   returns error status
 */
uint8_t solve_quadratic(const quad_coeffs_t coeffs, quad_roots_t *roots);

#endif // CM_EXAMPLE_QUADRATIC_H
