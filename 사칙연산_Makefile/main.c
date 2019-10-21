#include <stdio.h>
#include "lib/main.h"

void main(int argc, char *argv[]){
  printf("add(%d, %d) = %d\n", atoi(argv[1]),atoi(argv[2]), add(atoi(argv[1]),atoi(argv[2])));
  printf("sub(%d, %d) = %d\n", atoi(argv[1]),atoi(argv[2]), sub(atoi(argv[1]),atoi(argv[2])));
  printf("mult(%d, %d) = %d\n", atoi(argv[1]),atoi(argv[2]), mult(atoi(argv[1]),atoi(argv[2])));
  printf("divide(%d, %d) =  %d\n", atoi(argv[1]),atoi(argv[2]), divi(atoi(argv[1]),atoi(argv[2])));
}
