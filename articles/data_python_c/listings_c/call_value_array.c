# include <string.h>
# include <stdio.h>

struct string_wrapper{
  char string[10];
};

void func(char string[])
{
  
  /* Make modifications */
  string[0] = string[0] + 5;
  printf("String: %s\n", string);

  return;
}

int main(int argc, char **argv)
{

  struct string_wrapper string;

  char astring[] = "A String";
  strcpy(string.string, astring);

  printf("String: %s\n", astring);

  func(string.string);

  printf("String: %s\n", astring);
  

  return 0;
}
