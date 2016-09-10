#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "List.c"
#include "List.h"
#define MAX_LEN 160

List insertSort(char** array, int length){
  List list = newList();
  if (length > 0) append(list, 0);
  for (int j = 1; j < length; j++){
    char *temp = array[j];
    moveBack(list);
    while (index(list) > -1){
	if(strcmp(temp, array[get(list)]) < 0){
		movePrev(list);
	}else{
		insertAfter(list, j);
		break;
	}
	if(index(list) == -1){
		prepend(list, j);
		break;
	}
    }
  }
  return list;
 }

char*  stradd(const char *x){
  char *p = malloc(strlen(x) + 1);
  strcpy(p,x);
  return p;
}

int main(int argc, char* argv[]){
//  printf("foo");
  if(argc < 2){
    printf("Invalid number of inputs");
    exit(1);
  } 

  FILE* input = fopen(argv[1],"r");
  FILE* output = fopen(argv[2], "w");

  char values[MAX_LEN];
  int c=0;
  while(fgets(values, MAX_LEN, input) != NULL){ 
    c++;
  }

  fclose(input);
  input = fopen(argv[1],"r");

  char** array1 = malloc(sizeof(char**) * c);
  char arrayLine[MAX_LEN];
  for(int i=0; i<c; i++){
    fgets(arrayLine, MAX_LEN, input);
    array1[i] = stradd(arrayLine);  
  }

  for(int i =0; i<c; i++){
    printf("%s", array1[i]);
  }

  List  L = insertSort(array1, c);
  for(moveFront(L); index(L) >= 0; moveNext(L)){
   printf( "%s", array1[get(L)]);
  } 

  fclose(input);
  fclose(output);
  return(0);
}
