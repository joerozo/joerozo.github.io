#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>

typedef struct ListObj* List;
typedef struct NodeObj* Node;
List newList(void);
void freeList(List* N);

int length(List L);
int index(List L);
int front(List L);
int back(List L);
int equals(List A, List B);
int get(List L);

void moveFront(List L);
void clear (List L);
void movePrev(List L);
void moveNext(List L);
void prepend(List L, int data);
void append(List L, int data);
void insertBefore(List L, int data);
void insertAfter(List L, int data);
void deleteFront(List L);
void deleteBack(List L);
void delete(List L);
void moveBack(List L);

void printList (FILE* out, List L);
List copyList(List L);
List concat(List L, List L2);

#endif
