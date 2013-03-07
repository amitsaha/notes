# include <stdio.h>


int main(int argc, char **argv)
{
  int a = 1;
  const int b = a;

  /* Even though this is the same value as already stored in a,
     this is not known to the compiler at compile time. Hence, the
     following statement will result in a compile time error*/
  /*b = a;*/

  printf("Address of a: %p, Address of b: %p\n", &a, &b);
  printf("a = %d b = %d \n",a,b);

  return 0;
}
