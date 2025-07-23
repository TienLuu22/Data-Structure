#ifndef PLISTLIB_H
#define PLISTLIB_H

#include <stdio.h>

typedef int ElementType;
typedef struct NodeTag
{
  ElementType data;
  struct NodeTag *next;
} Node;

typedef Node *List;
typedef Node *Position; // Position of List

// Operator
//-----------------------------------------------//
//  void Operator

void makeNullList(List *L);
void InsertAt(ElementType x, int i, List *L);
void Delete(Position p, List *L);
void PrintList(List L);
void ReadList(List *L);
void append(ElementType x, List *L);
void setAt(ElementType x, int i, List *L);
void InsertFirst(int x, List *L);

// int Operator
//-----------------------------------------------//
int EmptyList(List L);
int FullList(List L);
int PopAt(int i, List *L);
int PopLast(List *L);
int PopFirst(List *L);
int Len(List L);

// Position Operator
//-----------------------------------------------//
Position FirstList(List L);
Position LastList(List L);
Position Next(int i, List L);
Position previous(Position p, List L);
Position locate(ElementType x, List l);
Position getPosition(int i, List L);

// ElementType Operator
//-----------------------------------------------//
ElementType getAt(int i, List L);

#endif // !PLISTLIB_H
