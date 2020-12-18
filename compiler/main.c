#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXCHAR 10000

char *code;





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

  while (fgets(str, MAXCHAR, fp) != NULL)
  {
    if(code == "" && str != "")
    {
      code = (char *)malloc(strlen(str));
      strcat(code, str);
    }
    else
    {
      code = (char *)realloc(code, strlen(code) + strlen(str));
      strcat(code, str);
    }
  }
  puts(code);
  fclose(fp);
 return 0;
}
