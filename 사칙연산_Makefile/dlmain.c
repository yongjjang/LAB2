#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "lib/main.h"

void main(int argc, char *argv[]){
  void *handle;
  int (*add)(int,int), (*divi)(int,int),(*sub)(int,int),(*mult)(int,int);
  char *error;

  handle = dlopen("./lib/libshared.so", RTLD_LAZY);
  if (!handle) {
    fputs(dlerror(), stderr);
    exit(1);
  }

  add = dlsym(handle, "add");
  if ((error = dlerror()) != NULL){
    fprintf (stderr, "%s", error);
    exit(1);
  }
  divi = dlsym(handle, "divi");
  if ((error = dlerror()) != NULL){
    fprintf (stderr, "%s", error);
    exit(1);
  }
  mult = dlsym(handle, "mult");
  if ((error = dlerror()) != NULL){
    fprintf (stderr, "%s", error);
    exit(1);
  }
  sub = dlsym(handle, "sub");
  if ((error = dlerror()) != NULL){
    fprintf (stderr, "%s", error);
    exit(1);
  }
  
  printf("add(%d, %d) = %d\n", atoi(argv[1]),atoi(argv[2]), add(atoi(argv[1]),atoi(argv[2])));
  printf("sub(%d, %d) = %d\n", atoi(argv[1]),atoi(argv[2]), sub(atoi(argv[1]),atoi(argv[2])));
  printf("mult(%d, %d) = %d\n", atoi(argv[1]),atoi(argv[2]), mult(atoi(argv[1]),atoi(argv[2])));
  printf("divide(%d, %d) =  %d\n", atoi(argv[1]),atoi(argv[2]), divi(atoi(argv[1]),atoi(argv[2])));

  dlclose(handle);
}
