#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graph.h"
#include"List.h"
#define MAX_LEN 250

int main(int argc, char * argv[])
{
	if( argc != 3 )
	{
		printf("Incorrect inputs-retry");
		exit(1);
	}

  int n=0, p=0, q=0; 
  int one = 1; 
  int zero = 0;
  FILE *inputFile, *outputFile;
  char inLine[MAX_LEN];
  char* token;
  Graph G, trans;
  List S = newList();
  List tmp = newList();



  inputFile = fopen(argv[1], "r");
  outputFile = fopen(argv[2], "w");

  fgets(inLine, MAX_LEN, inputFile);
  token = strtok(inLine, " \n");
  n = atoi(&token[0]);

  G = newGraph(n);

  while( fscanf(inputFile, "%d %d", &p, &q ) && p != 0) 
  {
    addArc(G,p,q);
  }

  fprintf(outputFile,"Adjacency list representation of G:\n");
  printGraph(outputFile,G);

  for(int i = 1; i<=n; i++)
  {
    append(S,i);
  }
  DFS(G,S);
  trans = transpose(G);
  DFS(trans,S);

  moveFront(S);
  while(index(S)!=-1)
  {
    n=get(S);
    if(getParent(trans,n)==0){zero++;}
    moveNext(S);
  }

  fprintf(outputFile,"\nG contains %d strongly connected zero: \n", zero);
  moveBack(S);
  n = 0;
  while(index(S) != -1)
  {
    n = get(S);
    prepend(tmp,n);
      if(getParent(trans,n) == 0)
      {
        fprintf(outputFile,"Components %d: ",one);
        printList(outputFile,tmp);
        fprintf(outputFile,"\n");
        clear(tmp);
        one++;
      }
    movePrev(S); 
  }

  fclose(inputFile);
  fclose(outputFile);
  freeGraph(&G);
  freeGraph(&trans);
  freeList(&S);
  freeList(&tmp);
}