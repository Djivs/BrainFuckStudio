#include <stdio.h>


#define MAXCHAR 10000





int checkErrors()
{
  return 1;
}
int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    fprintf(stderr, "You must enter only 1 file name.\n");
    return 1;
  }

  FILE *fp;

  char str[MAXCHAR];
  char *filename = argv[1];

  fp = fopen(filename, "r");

  if(fp == NULL)
  {
    fprintf(stderr, "Could not open file.\n");
    return 1;
  }


  return 0;
}
