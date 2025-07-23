#ifndef LISTLIB_A
#define LISTLIB_A
#define MaxSize 10000

#include<stdio.h>
#include<stdbool.h>

typedef int Position;
typedef int ElementType;

typedef struct{
	ElementType element[MaxSize];
	int Size;
}List;

void makeNullList(List *L);
void readList(List *L);
void printList(List L);
void setAt(Position p, ElementType x, List *L);
void insertAt(Position p, ElementType x, List *L);
void insertFirst(ElementType x, List *L);
void append(ElementType x, List *L);
void Bubblesort(List *L); 

int Len(List L);

bool emptyList(List L);
bool fullList(List L);

ElementType GetAt(Position p, List L);
ElementType popAt(Position p, List *L);
ElementType popFirst(List *L);
ElementType popLast(List *L);

Position first(List L);
Position endList(List L);
Position locate(ElementType x , List L);
Position next(Position p, List L);
Position previous(Position p, List L);


#endif
 


 