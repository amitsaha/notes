/*Listing-3: gsl_sort.c*/

/* Demonstration of GSL's sorting functions
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
  
  /* Allocate the vector of the specified size*/
  gsl_vector * v = gsl_vector_alloc (n);

  /* Set the elements to a uniform random number in [0,1]*/
  for (i = 0; i < n; i++)
    {
      gsl_vector_set (v, i, gsl_rng_uniform (r));
    }
       
  /* Print the vector*/
  printf("(Hopefully) Unsorted Vector:: ");
  for (i = 0; i < n; i++)
    {
      printf ("%g ", gsl_vector_get (v, i));
    }

  printf("\n");

  /* Sort the vector*/
  gsl_sort_vector(v);

  /* Print the sorted vector*/
  printf("Sorted Vector::               ");
  for (i = 0; i < n; i++)
    {
      printf ("%g ", gsl_vector_get (v, i));
    }
  printf("\n");


  
  /* Allocate a large vector*/
  gsl_vector * v_large = gsl_vector_alloc (10000);
  
  /* Set the elements to a uniform random number in [0,1]*/
  for (i = 0; i < 10000; i++)
    {
      gsl_vector_set (v_large, i, gsl_rng_uniform (r));
    }


  /* Find the 100 largest numbers from the above vector*/
  double *largest = malloc(10*sizeof(double));
  gsl_sort_vector_largest (largest, 10, v_large);

  printf("\n\n10 largest numbers:: \n\n");
  
  /* Print the 10 largest*/
  for (i = 0; i < 10; i++)
    printf("%g ",largest[i]);
  printf("\n\n");

  gsl_vector_free (v);
  free(largest);

  return 0;
}
