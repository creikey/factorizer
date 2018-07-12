#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char ** argv)
{
  if(argc <= 1)
  {
    printf("Usage:\n[number] - finds all factor pairs\n");
    return 1;
  }
  long to_factorize;
  char *end_ptr;
  to_factorize = strtol(argv[1], &end_ptr, 10);
  if(errno != 0)
  {
    printf("Failed to factorize: %s\n", strerror(errno));
    return 1;
  }
  printf("Factorizing: %ld\nThrown away data: %s\n", to_factorize, end_ptr);
  for(long i = 1; i <= to_factorize; i++)
  {
    if( (to_factorize / i) * i == to_factorize )
    {
      printf("%ld * %ld = %ld\n", (to_factorize / i), i, to_factorize);
    }
  }
  return 0;
}
