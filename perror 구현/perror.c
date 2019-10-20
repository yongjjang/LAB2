#include <errno.h>
#include <stdio.h>
#include <string.h>
extern int errno;

void my_perror(char str[]){
  if (str != NULL){
    strcat(str, " : ");
  }else{
    str = "";
  }
  
  switch (errno){
  case 1:
    printf("%sOperation not permitted \n", str);
    break;
  case 2:
    printf("%sNo such file or directory \n", str);
    break;
  case 3:
    printf("%sNo such process \n", str);
    break;
  case 4:
    printf("%sinterrupted system call \n", str);
    break;
  case 5:
    printf("%sI/O error \n", str);
    break;
  }
}
