/*Listing-2: gsl_vector_ops.c*/

/* Vector operations in GSL
 * Also uses the random number generation feature
 */

#include <stdio.h>
#include <gsl/gsl_vector.h> /*For Vectors*/
#include <gsl/gsl_rng.h> /* For Random numbers*/
     
int main ()
{
  int i,n;

  /* Setup the Random number generator*/
  const gsl_rng_type * T;
  gsl_rng * r;
  gsl_rng_env_setup();
  T = gsl_rng_default;
  r = gsl_rng_alloc (T);     
       
  
  printf("Number of elements in the vector:: ");
  scanf("%d",&n);
  
  /* Allocate the vectors of the specified size*/
  gsl_vector * v1 = gsl_vector_alloc (n);
  gsl_vector * v2 = gsl_vector_alloc (n);

  /* Set the elements to a uniform random number in [0,1]*/
  for (i = 0; i < n; i++)
    {
      gsl_vector_set (v1, i, gsl_rng_uniform (r));
      gsl_vector_set (v2, i, gsl_rng_uniform (r));
    }
       
  /* Print the vector*/
  printf("V1:: ");
  for (i = 0; i < n; i++)
    {
      printf ("%g ", gsl_vector_get (v1, i));
    }
  printf("\n");

  printf("V2:: ");
  for (i = 0; i < n; i++)
    {
      printf ("%g ", gsl_vector_get (v2, i));
    }
  printf("\n\n");

  printf(">>> Vector Operations >>> \n\n");


  /* v1+v2 gets stored in v1*/
  gsl_vector_add(v1,v2);

  printf("V1+V2:: ");
  for (i = 0; i < n; i++)
    {
      printf ("%g ", gsl_vector_get (v1, i));
    }
  printf("\n");


  /* v1-v2 gets stored in v1*/
  gsl_vector_sub(v1,v2);

  printf("V1-V2:: ");
  for (i = 0; i < n; i++)
    {
      printf ("%g ", gsl_vector_get(v1, i));
    }
  printf("\n");
  
    
  gsl_vector_free (v1);
  gsl_vector_free (v2);

  return 0;
}
