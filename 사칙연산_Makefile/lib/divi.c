#include <stdio.h>

int divi(int a, int b){
  if (b != 0)  {
    int result = a/b;
    return result;
  }
  else{
    printf("You must input Not 0\n");
    printf("Please Try again");
  }
}
