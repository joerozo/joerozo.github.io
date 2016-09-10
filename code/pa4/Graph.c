#include <stdlib.h>
#include "Graph.h"

static void insertsort(List L, int u);

#define WHITE 10000001
#define BLACK 19999991
#define GRAY  -6666669
struct GraphObj {
  List *array;
  int *colors;
  int *parents;
  int *distances;
  int verts; 
  int edges; // size
  int source; 
};

Graph newGraph(int n){ 
  Graph x = malloc(sizeof(struct GraphObj)); 
  x->array = calloc(n+1, sizeof(List)); 
  x->colors = calloc(n+1, sizeof(int)); 
  x->parents = calloc(n+1, sizeof(int)); 
  x->distances = calloc(n+1, sizeof(int));
  x->source = NIL;
  x->verts = n; 
  x->edges = 0; 
  for (int i = 0; i < n + 1; i++){
    x->array[i] = newList();
    x->colors[i] = WHITE;
    x->parents[i] = NIL; 
    x->distances[i] = INF; 
  }
  return x;
}

// frees all dynamic memory associated with Graph 
void freeGraph(Graph* pG){
  Graph freed = *pG; 
  for(int i = 0; i < (freed->verts) + 1; i++){
    freeList(&(freed->array[i]));
  }
  free(freed->array); 
  free(freed->colors); 
  free(freed->parents); 
  free(freed->distances); 
  free(*pG);
  *pG = NULL; 
} 

 


int getOrder(Graph G){
  return G->verts;
}

int getSize(Graph G){
  return G->edges;
}

int getSource(Graph G){
  return G->source;
}

int getParent(Graph G, int u){
  return G->parents[u];
}

// returns the distance of the vertex from source 
int getDist(Graph G, int u){
  if(getSource(G) == NIL){
    return INF;
  }
  return G->distances[u];
}
 

void getPath(List L, Graph G, int u){
  if(getSource(G) == NIL){
    printf("use BFS()");
  }
  int s = G->source;
  if (u == s){
    prepend(L, s);
    return;
  } else if (G->parents[u] == NIL) {
    append(L, NIL);
  } else {
    prepend(L,u);
    getPath(L, G, G->parents[u]);
  }
} 


void makeNull(Graph G){
  for(int i = 0; i < G->verts + 1; i++){
    clear(G->array[i]);
  } 
}


void addEdge(Graph G, int u, int v){
  List x1 = G->array[x1];
  List x2 = G->array[x2];
  insertsort(x1, x2);
  insertsort(x2, x1);
}


static void insertsort(List L, int u){
  if (length(L) == 0){
    append(L, u);
    return;
  }
  for(moveFront(L); index(L) >= 0; moveNext(L)){
    int big = get(L);
    if(u < big){
      insertBefore(L, u);
      break;
    }
  }
  if(index(L) == -1){
    append(L, u);
  }
}
 
// adds a directed edge
void addArc(Graph G, int u, int v){
  List U = G->array[u];
  insertsort(U, v);
}
 

void BFS(Graph G, int s){
  for (int u = 0; u < G->verts + 1; u++){
    if(u != s){
      G->colors[u] = WHITE;
      G->distances[u] = INF;
      G->parents[u] = NIL;
    }
  }

  G->source = s;
  G->colors[s] = GRAY;
  G->distances[s] = 0;
  G->parents[s] = NIL;

  List Q = newList();
  prepend(Q, s);
  while(length(Q) > 0){
    int u = back(Q);
    deleteBack(Q);
    List adj = G->array[u];

    for(moveFront(adj); index(adj)>=0; moveNext(adj)){
      int vertex = get(adj);
      if(G->colors[vertex] == WHITE){
    G->colors[vertex] = GRAY;
    G->distances[vertex] = G->distances[u] + 1;
    G->parents[vertex] = u;
    prepend(Q, vertex);
      }
    }

    G->colors[u] = BLACK;
  }

  freeList(&Q);
} 


void printGraph(FILE* out, Graph G){
  for (int i = 1; i < getOrder(G) + 1; i++){
    fprintf(out, "%d: ", i);
    printList(out, G->array[i]);
    fprintf(out, "\n");
  }
}


