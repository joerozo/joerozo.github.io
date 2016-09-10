#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "List.c"
#include "List.h"
#define MAX_LEN 160

List insertSort(char** array, int length){
	// makes a new list object
	printf("list err");
	List list = newList();
	printf("list err");
	// appends first element
	if (length > 0) append(list, 0);
	for (int j = 1; j < length; j++){
		char *temp = array[j];
		int i = j - 1;
		printf("i=j-1  err");
		moveFront(list);printf("moveFront  err");
		//sorting
		while (i > -1 && strcmp(temp, array[get(list)]) < 0){
			("strCMP  err");
			i--;
			movePrev(list);
		}

		if(index(list) == -1){
			prepend(list, j);
		} else {
			insertAfter(list, j);
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
//	printf("foo");
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
		printf("%s\n", array1[i]);
	//	printf("thisisarray");
	}
	printf("now sorting\n");
	List D = newList();
	D = insertSort(array1, c);
	//for(moveFront(L); index(L) >= 0; moveNext(L)){
	// fprintf(output, "%s", array1[get(L)]);
	//:} 

	fclose(input);
	fclose(output);
	return(0);
}
