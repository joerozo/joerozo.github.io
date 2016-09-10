#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"
#include "List.h"

int main(int argc, char* argv[]){
		
   Graph G = NULL, trans = NULL;
   List S = newList();
   time_t t;
   time(&t);
   int i,a;

   srand((int)t);
	//change this for different sized graphs, recompile with many different size graphs 
   int n = rand() % 101;

   //change this for different sources for BFS(), recompile with many different sources
  // int source = (rand() % n) + 1;

   // Build graph G, test contructor
   G = newGraph(n);
   a = n - 7;

	//make sure addEdge(), and therefore addArc(), can build a graph
   addArc(G, 4, 6);
   addArc(G, 6,3);

	for(i=2; i< n; i++)
	{
		if( i % 7 != 0 )
		{ 
			addArc(G, i, i+1);
		}
		if( i < a  ) 
		{
			addArc(G, i, i+7);
		}
	}
	//test to make sure addArc is inserting arcs in assending order
	addArc(G, 7, 3);
	addArc(G, 2, 5);
	addArc(G, 2, 4);

  fprintf(stdout,"\n\n\nGraph G is of order: %d \n\n\n", getOrder(G));

	fprintf(stdout,"------------Adjacency Matrix--------------\n\n\n");
   	// Print adjacency list representation of G
  printGraph(stdout, G);
  	//	TestFunctions
  	
  Graph cpy = NULL;
  cpy = copyGraph(G);
  fprintf(stdout,"------------copyGraph() called---------------\n\n\n");
  printGraph(stdout, cpy);

	for(i = 1; i<=getOrder(G); i++){
		append(S, i);
	}
	fprintf(stdout, "------%d-------\n", length(S));
	fprintf(stdout, "------%d-------\n\n\n",getOrder(G));
	fprintf(stdout, "\n\n\n------------DFS() Called-------------\n\n\n");
	DFS(G, S);
  fprintf(stdout, "\n");
  fprintf(stdout, "x:  d  f  p\n");
  for(i=1; i<=n; i++){
    fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(G, i), getFinish(G, i), getParent(G, i));
  }
  fprintf(stdout, "\n");
  printList(stdout, S);
 	fprintf(stdout, "\n");


  trans = transpose(G);
  fprintf(stdout,"------------transpose() called---------------\n\n\n");
  printGraph(stdout,trans);
    
  fprintf(stdout,"\n\n\n------------DFS() Called on transpose of G-----------\n\n\n");
	DFS(trans, S);
  fprintf(stdout, "\n");
  fprintf(stdout, "x:  d  f  p\n");
  for(i=1; i<=n; i++){
    fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(trans, i), getFinish(trans, i), getParent(trans, i));
  }
  fprintf(stdout, "\n");
  printList(stdout, S);
  fprintf(stdout, "\n");


  freeGraph(&G);
  freeGraph(&cpy);
  freeGraph(&trans);
  freeList(&S);
  return(0);
}
