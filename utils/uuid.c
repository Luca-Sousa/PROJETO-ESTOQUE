#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *uuid(int length)
{
  char *result = (char *)malloc(length + 1);
  srand(time(NULL));

  for (int i = 0; i < length; i++)
  {
    int digit = rand() % 10;
    result[i] = '0' + digit;
  }

  result[length] = '\0';
  return result;
}
