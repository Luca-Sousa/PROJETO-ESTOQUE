#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// char *uuid()
// {
//   char v[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//   char *uuid;
//   uuid = (char *)malloc(8 * sizeof(char));

//   for (int i = 0; i < 7; i++)
//   {
//     uuid[i] = v[rand() % 9];
//   }

//   // printf("%s", uuid);
//   return uuid;
// }

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

// int main()
// {
//   char *str = random_string(10);
//   printf("%s", str);
//   return 0;
// }