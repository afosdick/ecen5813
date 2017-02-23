#include <stdio.h>
#include <stdlib.h>

#include "quadratic.h"

int main(int argc, char **argv)
{
  quad_coeffs_t coeffs;
  coeffs.a = 2.0;
  coeffs.b = -3.0;
  coeffs.c = -2.0;
  printf("solving : %2.1f * x^2 + %2.1f * x + %2.1f = 0\n", coeffs.a, coeffs.b, coeffs.c);
  quad_roots_t roots;
  uint8_t status = solve_quadratic(coeffs, &roots);
  if (QUAD_SUCCESS == status) {
    printf("roots = (%f, %f)\n", roots.root_1, roots.root_2);
  } else if (QUAD_ERROR_a_equals_0 == status) {
    printf("error: a must be greater than zero.\n");
  } else if (QUAD_ERROR_imaginary_roots == status) {
    printf("error: imaginary roots : b^2-4ac < 0.\n");
  }
  return EXIT_SUCCESS;
}
