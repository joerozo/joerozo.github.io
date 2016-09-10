#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "List.h"

#define MAX_LEN 160

// carries out a variation of the insertion sort
List insertsort(char array[][MAX_LEN], int length){
  // makes a new list object
  List list = newList();

  // appends first element
  if (length > 0) append(list, 0);
  for (int j = 1; j < length; j++){
    char *temp = array[j];
    int i = j - 1;
    //move cursor to current position
    moveFront(list);
    
    //sorting
    while (index(list) > -1 && strcmp(temp, array[get(list)]) < 1){
      i--;
      movePrev(list);
    }
    
    // if cursor is null, then prepend
    // otherwise insert after it
    //get
    if(index(list) == -1){
      prepend(list, j);
    } else {
      insertAfter(list, j);
    }
  }

  return list;
}


int main(int argc, char* argv[]){
  int count = 0;
  char line[MAX_LEN];
  char tokenlist[MAX_LEN];
  char strings[count][MAX_LEN];
  char *token;

  if(argc != 3) {
    printf("Invalid number of inputs");
    exit(1);
  }
  
  FILE* input = fopen(argv[1], "r");
  FILE* output = fopen(argv[2], "w");

  if(input == NULL){ 
    printf("Unable to open file %s for reading\n", argv[1]);
    return 1;
  } else if (output == NULL){
    printf("Unable to open file %s for reading\n", argv[2]);
    return 1;
  }

  // read each line of input file, then count and print tokens
  while( fgets(line, MAX_LEN, input) != NULL) {
    count++;
  }

  // close and reopen file to reset fgets
  fclose(input);
  input = fopen(argv[1], "r");

  for(int i = 0; fgets(line, MAX_LEN, input) != NULL; i++){
    token = strtok(line, "\n");
    tokenlist[0] = '\0';

    while(token != NULL){
      strcat(tokenlist, token);
      token = strtok(NULL, " \n");
      
    // appends new lines to the end of every line
      strncat(tokenlist, "\n", 10);
    }

    strcpy(strings[i], tokenlist);
  }

  
  List L = insertsort(strings, count);
  for(moveFront(L); index(L) >= 0; moveNext(L)){
    fprintf(output, "%s", strings[get(L)]);
  }


  //for(moveFront(L); i(L) >= 0; moveNext(L)){
        // fprintf(output, "%s", array1[get(L)]);
        //:} 



  //close files
  fclose(input);
  fclose(output);

  return(0);
}