#include <stdio.h>

int main()
{
  // Create a 32 bit integer
  int an_int = 1;

  // Make a char* with the address of the integer
  // A char is only 1 byte so you will only look at the 
  // first byte (lowest address) of the integer
  char* ptr = (char*) &an_int;

  // Cast the value at the char* to an integer
  if (((int) *ptr) == 1)
    printf("The system is little endian\n");
  else
    printf("The system is big endian\n");
  
  return 0;
}
