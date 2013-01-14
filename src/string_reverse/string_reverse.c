#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
  // Read string from a file
  FILE* file_ptr = fopen("test.txt", "r");

  if (file_ptr == NULL)
    return 1;

  char* string = malloc(256);

  fscanf(file_ptr, "%s", string);

  // Solution
  
  int length = sprintf(string, "%s", string);
  
  int front = 0;
  int back = length - 1;

  while(front < back)
  {
    // swap 2 characters
    char tmp = string[front];
    string[front] = string[back];
    string[back] = tmp;

    ++front;
    --back;
  }

  printf("%s\n", string);

  return 0;
}
