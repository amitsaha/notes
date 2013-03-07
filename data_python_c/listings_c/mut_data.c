/* Variables are by default mutable.
 */
# include <stdio.h>

int a = 1;

int main(int argc, char **argv)
{
  int b;

  /*Copy the value stored in a to b*/
  b = a;

  /* A no-op operation*/
  2;

  /* The & operator expects an 'lvalue' as an operand, and hence
     the following statement will result in a compilation error. 
   */
  /*printf("Address of 2 %p\n", &2);*/

  printf("Address of a: %p, Address of b: %p\n", &a, &b);
  printf("a = %d b = %d \n",a,b);

  /* Change value stored in the memory location identified as a.
   */
  a = 2;

  printf("Address of a: %p, Address of b: %p\n", &a, &b);
  printf("a = %d b = %d \n",a,b);

  return 0;
}
