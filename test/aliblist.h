#ifndef LISTLIB
#define LISTLIB
#define MaxLength 1000
typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Element[MaxLength];
} List;
void MakeNullList(List *L);
int insertList(ElementType x, Position p, List *L);
Position locatelist(ElementType x, List *L);
ElementType retrieveList(Position p, List *L);
int deleteList(Position p, List *L);
Position nextList(Position p, List *L);
Position previousList(Position p, List *L);
Position firstList(List *L);
int emptyList(List *L);
Position endList(List *L);
void printList(List *L);
void fullList(List *L);

#endif