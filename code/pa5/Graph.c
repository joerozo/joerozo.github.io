#include <stdlib.h>
#include "Graph.h"

//static void insertSort(List L, int u);
// void Visit(Graph G, int x, List P);
#define WHITE 1005
#define BLACK 1999
#define GRAY  -5555
#define INF (-500)
#define DEBUG (0)
struct GraphObj {
  List *array;
  int *colors;
  int *parents;
  int *discover;
  int *finish;
  int time; 
  int vertices; // size
  int edges; 
};

Graph newGraph(int n){ 
 Graph x = malloc(sizeof(struct GraphObj));
 x->array = calloc(n+1, sizeof(List));
 x->colors = calloc(n+1, sizeof(int));
 x->parents = calloc(n+1, sizeof(int));
 x->discover =  calloc(n+1, sizeof(int));
 x->time = 0;
 x->finish = calloc(n+1, sizeof(int));
 x->vertices = n;
 x->edges = 0;
 for(int i = 1; i <= n; i++){
  x->array[i] = newList();
  x->colors[i] = WHITE;
  x->parents[i] = NIL;
  x->discover[i] = UNDEF;
  x->finish[i] = UNDEF;
}
return x;
}


// frees all dynamic memory associated with Graph 
void freeGraph(Graph* pG){
  Graph x = *pG;
  for(int i = 0; i<x->vertices; i++){
    free(x->array);
    free(x->colors);
    free(x->parents);
    free(x->discover);
    free(*pG);
    *pG = NULL;
  }
} 

 


int getOrder(Graph G){
  return G->vertices;
}

int getSize(Graph G){
  return G->edges;
}

int getParent(Graph G, int u){
  if(1 <= u && u <= getOrder(G)){
    return G->parents[u];
}
  return 0;
}

int getDiscover(Graph G, int u){
  if(1 <= u && u <= getOrder(G)){
    return G->discover[u];
  }
  return 0;
}

int getFinish(Graph G, int u){
  if(1 <= u && u <= getOrder(G)){
   return G->finish[u];
  }
  return 0;
}

// void getPath(List L, Graph G, int u){
//   if(getSource(G) == NIL){
//     printf("use BFS()");
//   }
//   int s = G->source;
//   if (u == s){
//     prepend(L, s);
//     return;
//   } else if (G->parents[u] == NIL) {
//     append(L, NIL);
//   } else {
//     prepend(L,u);
//     getPath(L, G, G->parents[u]);
//   }
// } 


// void makeNull(Graph G){
//   for(int i = 0; i < G->verts + 1; i++){
//     clear(G->array[i]);
//   } 
// }


// void addEdge(Graph G, int u, int v){
//   List x1 = G->array[x1];
//   List x2 = G->array[x2];
//   insertSort(x1, x2);
//   insertSort(x2, x1);
// }


void insertSort(List L, int u){
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
 

void addArc(Graph G, int u, int v){
  if(1 <= u && u <= getOrder(G) && 1 <= v && v <= getOrder(G)){
    List x = G->array[u];
    insertSort(x, v);
  }
  //printf("Addarc: incorrect inputs\n");
  return;
}



// void addArc(Graph G, int u, int v){
//   if(u < 1 || u > getOrder(G) || v < 1 || v > getOrder(G)){
//     printf("Addarc: preconditions not met\n");
//     printf("%d %d\n", u, v);
//     return;
//   }
//   List U = G->array[u];
//   insertSort(U, v);
// }

// void addEdge(Graph G, int u, int v){
//   if(1 <= u && u <= getOrder(G) && 1 <= v && v <= getOrder(G)){
//     List x1 = G->array[u];
//     List x2 = G->array[v];
//     insertSort(x1, v);
//     insertSort(x2, u);
//   }else{
//   printf("Addedge: incorrect inputs\n");
//   return;
//   }
// }
// static int time; 
// Visit(Graph G, int u, int time_u){
//   G->colors[u] = GRAY;
//   time = time_u;
//   G->discover[u] = ++time;
// }

// void DFS(Graph G, List S){
//   time = 0;
//   stack =  newList();
//   for(moveFront(S); index(S) != -1; moveNext(S)){
//     if(G->colors[get(S)] == WHITE){
//       Visit(G, getElement(S), timeStatic);
//     }
//   }
// }



void Visit(Graph G, int x, int* t, List Q){
  if(DEBUG) printf("visiting vertex %d\n", x);

    // append(Q, x);
  G->colors[x] = GRAY;
  G->discover[x] = (int)(++(*t));

  List LX = (G->array[x]);

  moveFront(LX);
  for(; index(LX) > -1; moveNext(LX)) {
    if(G->colors[get(LX)] == WHITE) {
      G->parents[get(LX)] = x;
            // append(Q, x);
      Visit(G, get(LX), t, Q);
    }
  }

  G->colors[x] = BLACK;
  G->finish[x] = (int)(++(*t));

  if(index(Q) > -1) 
    insertAfter(Q, x);
  else
    append(Q, x);
}


void throwException(char* errorMsg){
  printf("RunTime Error");
  exit(1);
}

void DFS(Graph G, List S){
  if(length(S) != getOrder(G)) 
    throwException("wrong lengths");

  int* _time = malloc(sizeof(int));
  for(int i = 1; i <= getOrder(G); ++i){
    G->colors[i] = WHITE;
    G->parents[i] = NIL;
    G->discover[i] = INF;
    G->finish[i] = INF;
  }

  *_time = 0;

  moveBack(S);
  for(int i = 1; i <= getOrder(G); ++i){
        // moveFront(S);
    if(G->colors[front(S)] == WHITE) Visit(G, front(S), _time, S);
    deleteFront(S);
  }

  if(DEBUG) {
    for(int i = 1; i <= getOrder(G); ++i){
      printf("%3d: %3d %3d %3d %3d\n", i, G->colors[i], 
        G->discover[i], 
        G->finish[i], G->parents[i]);
    }
  }

  free(_time);
}


Graph transpose(Graph G){
  int n = G->vertices;
  Graph x = malloc(sizeof(struct GraphObj));
  x->array = calloc(n+1, sizeof(List));
  x->colors = calloc(n+1, sizeof(int));
  x->parents = calloc(n+1, sizeof(int));
  x->discover = calloc(n+1, sizeof(int));
  x->finish =  calloc(n+1, sizeof(int));
  x->vertices = G->vertices;
  x->edges = G->edges;
  for(int i = 0; i <= n; i++){
    x->array[i] = newList();
    x->colors[i] = WHITE;
    x->parents[i] = NIL;
    x->discover[i] = UNDEF;
    x->finish[i] = UNDEF;
  }  
  for(int i = 1; i <= n; i++){
    List l = G->array[i];
    for(moveFront(l); index(l) >= 0; moveNext(l)){
      append(x->array[get(l)], i);
    }
  }
  return x; 
}

Graph copyGraph(Graph G){
  int n = G->vertices; 
  Graph x = malloc(sizeof(struct GraphObj));
  x->array = calloc(n+1, sizeof(List));
  x->colors = calloc(n+1, sizeof(int));
  x->parents = calloc(n+1, sizeof(int));
  x->discover = calloc(n+1, sizeof(int));
  x->finish =  calloc(n+1, sizeof(int));
  x->vertices = G->vertices;
  x->edges = G->edges;
  for(int i = 1; i <= n; i++){
    x->array[i] = newList();
    List l = G->array[i];
    for(moveFront(l); index(l) >= 0; moveNext(l)){
      append(x->array[i], get(l));
    }
    x->colors[i] = WHITE;
    x->parents[i] = NIL;
    x->discover[i] = UNDEF;
    x->finish[i] = UNDEF;
  }
  return x;
}

void printGraph(FILE* out, Graph G){
  
  for (int i = 1; i < getOrder(G) + 1; i++){
    fprintf(out, "%d: ", i);
    printList(out, G->array[i]);
    fprintf(out, "\n");
  }
}
