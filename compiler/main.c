#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHAR 10000
void error(char *msg)
{
  fprintf(stderr, "%s\n", msg);
  exit(1);
}
void checkErrors(char *code)
{
  int brackets = 0;
  for(int i = 0; i < strlen(code); ++i)
  {
    switch(code[i])
    {
      case '[':
        ++brackets;
        for(int j = i+1; j < strlen(code) && brackets; ++j)
        {
          switch(code[j])
          {
            case '[':
              ++brackets;
              break;
            case ']':
              --brackets;
              break;
          }
        }
        if(brackets)
          error("Invalid brackets.");
        break;
      case ']':
        ++brackets;
        for(int j = i-1; j >= 0 && brackets; --j)
        {
          switch(code[j])
          {
            case '[':
              --brackets;
              break;
            case ']':
              ++brackets;
              break;
          }
        }
        if(brackets)
          error("Invalid brackets.");
    }
  }
}
int main(int argc, char *argv[])
{
  if(argc > 2)
    error("Too many arguments");
  else if(argc != 2)
    error("No arguments");
  FILE *fp;
  char str[MAXCHAR];
  char *filename = argv[1];
  fp = fopen(filename, "r");
  char *code;
  if(fp == NULL)
    error("Could not open file");
  fseek(fp, 0, SEEK_END);
  long lenght = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  code = (char *)malloc(lenght);
  fread(code, sizeof(char), lenght, fp);
  fclose(fp);
  checkErrors(code);
  puts(code);
 return 0;
}
