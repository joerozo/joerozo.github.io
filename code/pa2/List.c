#include <stdlib.h>
#include "List.h"

typedef struct NodeObj*Node;

struct NodeObj{
        int value;
        Node next;
        Node previous;
};

    typedef struct ListObj{
        Node cursor;
        Node front;
        Node back;
        int length;
        int index;
    }ListObj;

    List newList(){
        List x = malloc (sizeof(struct ListObj));
        x->cursor=NULL;
        x->front=NULL;
        x->back=NULL;
        x->length=0;
        x->index=-1;
        return x;
    }

    void freeList(List* N){
        if(*N==NULL){
            printf("NULL POINTER ERR");
        }
        clear(*N);
        free(*N);
        *N=NULL;
        }

        int length(List L){
            if(L==NULL){
                return -1;
            }
            return L->length;
        }

    int index(List L){
        if(L==NULL){
            return -1;
        }
        return L->index;
    }

    int front(List L){
        if(L->length > 0){
            return L->front->value;
        }
        return -1;
    }

    int back(List L){
        if(L->length > 0){
            return L->back->value;
        }
        return -1;
    }

/*    int front(List N){
        if(N-length > 0){
            return N->length->value;
        }
        return -1;
    } */

    int get (List L){
        if(L->length>0 && L->index >= 0){
            return L->cursor->value;
        }
        return -1;
    }

    int equals(List A, List B){
        Node x1 = A->front;
        Node x2 = B->front;
        while(x1!=NULL && x2!=NULL){
            if(x1->value != x2->value){
                return 0;
            }
            x1=x1->next;
            x2=x2->next;
        }
        return 1;
    }

    void clear(List L){
        Node x = L->front;
        while(x!=NULL){
            Node temp = x->next;
            free(x);
            x=temp;
        }
        L->cursor = NULL;
        L->front = NULL;
        L->back = NULL;
        L->length = 0;
        L->index = -1;
    }

    void moveFront(List L){
        if(L->front != NULL){
            L->cursor = L->front;
            L->index = 0;
        }
    }

    void moveBack(List L){
        if(L->back != NULL){
            L->cursor = L->back;
	    L->index = L->length-1;
        }
   }

    void movePrev(List L){
        if(L->index >=0 && L->index <= L->length-1){
            L->cursor = L->cursor->previous;
            L->index--;
        }else{
            L->cursor=NULL;
        }

    }

    void moveNext(List L){
        if (L == NULL) {
            printf("List.c: 179: passing null ptr to moveNext");
            return;
        }

        if(L->index >= 0 && L->index < L->length - 1){
            L->cursor = L->cursor->next;
            L->index++;
        } else {
            L->cursor = NULL;
            L->index = -1;
    }
}
        /*if(L->index >0 && L->index <= L->length-1){
            if(L->cursor != L->back){
                L->cursor = L->cursor->next;
                L->index++;
            }else{
                L->index = -1;
                L->cursor = NULL;
            }
        }
        printf("EMPTY LIST ERR");
    }*/

    void prepend (List L, int x){
        Node n = malloc(sizeof(struct NodeObj));
        n->value = x;
        L->index++;
        L->length++;
        if(L->front != NULL){
            L->front->previous = n;
            n->next = L->front;
            L->front = n;
        }else{
            L->back = n;
        }
        L->front = n;
    }

    void append(List L, int data){
        Node n = malloc(sizeof(struct NodeObj));
        n->value = data;
        L->index++;
        L->length++;

        if(L->back != NULL){
            L->back->next = n;
            n->previous = L->back;
        }else{
            L->front = n;
        }
        L->back = n;
    }

    void insertBefore(List L, int data){
        Node n = malloc(sizeof(struct NodeObj));
        L->length++;
        n->next = L->cursor;
        n->value = data;
        if(L->length >0 && L->index >=0){
            if(L->cursor->previous != NULL){
                L->cursor->previous->next=n;
            }else{
                L->front=n;
            }
            L->cursor->previous = n;
        }
    }


    void insertAfter(List L, int data){
        Node n = malloc(sizeof(struct NodeObj));
        L->length++;
        n->previous = L->cursor;
        n->next = L->cursor->next;
        if(L->length >0 && L->index >=0){
            if(L->cursor->next != NULL){
                L->cursor->next->previous = n;
            }else{
                L->back = n;
            }
            L->cursor->next = n;
        }
    }

    void deleteFront(List L){
        if(L->length>0){
                L->front =L->front->next;
                L->front->previous = NULL;
                }
        }    

    void deleteBack(List L){
        if(L->length>0){
            L->back = L->back->previous;
            L->back->previous = NULL;
        }
    }

    void delete(List L){
        if(L->length > 0 && L->index >=0){
            L->length--;
            L->cursor->value = -1;
            L->cursor->next->previous = L->cursor->previous;
            L->cursor->previous->next = L->cursor->next;
        }
        if(L->cursor == L->front){
            deleteFront(L);
        }
        if(L->cursor == L->back){
            deleteBack(L);
        }
    }

    void printList(FILE* out, List L){
      Node N = L->front;
      while(N != NULL){
        fprintf(out, "%d ", N->value);
        N = N->next;
      }
    }

    List copyList(List L){
        List x = newList();
        Node N = L->front;
        while(N != NULL){
            append(x, N->value);
            N = N->next;
        }
        return x;
    }

    List concat(List L, List L2){
        List T = copyList(L);
        Node N = L2->front;
        while(N != NULL){
            append(T, N->value);
            N = N->next;
        }
        return T;
    }







    


