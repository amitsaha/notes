# include <string.h>
# include <stdio.h>

void func(int *a, char *string)
{

  printf("In func()\n");

  printf("Address of a: %p \n", a);
  printf("Address of string: %p \n", &string[0]);

  printf("a = %d string = %s\n\n",*a, string);

  /* Make modifications */
  *a = *a+1;
  string[0] = string[0] + 5;

  printf("After modification in func()\n");
  printf("a = %d string = %s\n\n",*a, string);

  return;
}

int main(int argc, char **argv)
{

  int a = 5;
  char string[] = "A String";

  printf("In main() before func()\n");

  printf("Address of a: %p \n", &a);
  printf("Address of string: %p \n", &string[0]);

  printf("a = %d string = %s\n\n",a, string);

  func(&a, string);

  printf("In main() after func()\n");

  printf("a = %d string = %s\n\n",a, string);
  return 0;
}
