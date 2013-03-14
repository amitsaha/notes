/*Listing-4: gsl_fmin.c*/
/* Demonstration of using the function minimizing features
   in GSL */

#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_min.h>
     
/* Function: 2x^2 + 4x having a minimum at x=-1*/
double fn_1 (double x, void * params)
{
  return 2*x*x + 4*x;
}
     
int main ()
{
  int status;
  int iter = 0, max_iter = 100; /*Max. number of iterations*/
  const gsl_min_fminimizer_type *T;
  gsl_min_fminimizer *s;
  double m = 0.7; /* Starting point for the search*/
  double a = -4.0, b = 1.0; /* The interval in which the minimum lies*/
  gsl_function F;
     
  F.function = &fn_1; /* Function to Minimize*/
  F.params = 0;
     
  T = gsl_min_fminimizer_goldensection; /*Set the minimization algorithm - Uses Golden Section*/
  s = gsl_min_fminimizer_alloc (T); /* Initialize the minimizer*/
  gsl_min_fminimizer_set (s, &F, m, a, b); /*Set up the minimizer*/
     
  printf ("Using %s method\n", gsl_min_fminimizer_name (s));
  printf ("%5s [%9s, %9s] %9s \n","iter", "lower", "upper", "min", "err", "err(est)");
  printf ("%5d [%.7f, %.7f] %.7f \n",  iter, a, b, m);

  /* Set up the iterative minimization procedure*/
     
  do
    {
      iter++;
      status = gsl_min_fminimizer_iterate(s);
     
      m = gsl_min_fminimizer_x_minimum (s);
      a = gsl_min_fminimizer_x_lower (s);
      b = gsl_min_fminimizer_x_upper (s);
     
      status = gsl_min_test_interval (a, b, 0.001, 0.0);
     
      if (status == GSL_SUCCESS)
	printf ("Converged:\n");
     
      printf ("%5d [%.7f, %.7f] %.7f\n",iter, a, b, m);
    } while (status == GSL_CONTINUE && iter < max_iter);
     
  gsl_min_fminimizer_free (s);
     
  return status;
}
