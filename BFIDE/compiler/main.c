#include <stdio.h>
int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    fprintf(stderr, "You must enter only 1 file name.");
    return 1;
  }
  return 0;
}
