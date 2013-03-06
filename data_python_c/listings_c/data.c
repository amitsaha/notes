# include <stdio.h>

int a=1;

int main(int argc, char **argv)
{
  int b;

  /* Assignment operation effectively creates a copy of 
     the value stored in 'a' and stores it in 'b'
   */
  b=a;

  /* this is a no-op operation
     This is a valid C expression, but there is no visible
     effect of this operation
  */
  2;

  printf("b = %d\n",b);

  printf("Size of integer %d\n", sizeof(2));

  return 0;
}
