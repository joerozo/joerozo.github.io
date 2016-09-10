#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Graph.h"
#define MAX_LEN 200

int main (int argc, char* argv[]){
  char temp[MAX_LEN];

  if(argc != 3) {
    printf("Enter correct inputFiles");
    exit(1);
  }


  FILE* inputFile = fopen(argv[1], "r");
  FILE* outputFile = fopen(argv[2], "w");
  fgets(temp, MAX_LEN, inputFile);
  int nums = 0;
  sscanf(temp, "%d", &nums);
  
  Graph G = newGraph(nums);
  while( fgets(temp, MAX_LEN, inputFile) != NULL) {
    int x1 = 0;
    int x2 = 0;
    sscanf(temp, "%d %d", &x1, &x2);
    if(x1 == 0 && x2 == 0) break;
    addEdge(G, x1, x2);
  }
  printGraph(outputFile, G);
  // print path and compute distances
  List L;
  // this is just to elminate the starting newtemp
  int start = 0;

}