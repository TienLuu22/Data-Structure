#include <stdio.h>
#include <stdlib.h>
#include "plistlib.h"

// void Operator

void makeNullList(List *L)
{
    (*L) = (Node *)malloc(sizeof(Node)); // sentinel node or dummy node
    (*L)->next = NULL;
}

void InsertAt(ElementType x, int i, List *L)
{
    if (i < 0 || i > Len(*L)) // check the index location is valid or not
    {
        printf("Invalid index!\n");
        return;
    }

    Position p = getPosition(i, *L); // use getPosition to find the location we want ot insert an element
    Position NewNode = (Node *)malloc(sizeof(Node));
    NewNode->data = x;       // assgin value to the new node
    NewNode->next = p->next; // link the new node to the next current node
    p->next = NewNode;       // link the current node to the new node
}

void Delete(Position p, List *L)
{
    if (p == NULL || p->next == NULL) // check condition if the position is valid or invalid
    {
        printf("Invalid Position!\n");
        return;
    }
    if(p->next->next == NULL) // if the next node is the last node
    {
        free(p->next);//if the next node is the last node, we free it 
        p->next = NULL;// set the next node to NULL
        return;
    }
    Position Temp = p->next; //store the next node in a temporary variable
    p->next = Temp->next; // link the current node to the next node
    free(Temp);// free the temporary variable
}

void PrintList(List L)
{
    Position p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void ReadList(List *L)
{
    makeNullList(L); //initialize the list
    int n; //number of elements 
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        append(x, L);
    }
}

void append(ElementType x, List *L)
{
    Position p = *L; // start form the sentinel node
    while (p->next != NULL)// loop until we reach the last node
    {
        p = p->next;
    }
    Position NewNode = (Position)malloc(sizeof(Node)); // create a new node to store the value
    NewNode->data = x;
    NewNode->next = NULL; // set the next pointer of the new node to NULL
    p->next = NewNode; // link the last node to the new node now new node is the last node
}

void setAt(ElementType x, int i, List *L) // this function sets the new value at the given index
{
    Position p = getPosition(i, *L); // get the position of the index
    if (p->next != NULL) //check if the position is valid
    {
        p->next->data = x; // set the new value to the next node
    }
}

void InsertFirst(int x, List *L)
{
    InsertAt(x, 0, L);
}

// int Operator
int EmptyList(List L)
{
    return (L->next == NULL);
}

int FullList(List L)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        return 1;
    }
    free(temp);
    return 0;
}

int PopAt(int i, List *L)
{
    if (i < 0 || (*L) == NULL) // check if the index is valid or if the list is empty
    {
        printf("Invalid index or empty list!\n");
        return 0;
    }
    Position p = getPosition(i, *L); //get the position of the index
    if (p == NULL || p->next == NULL)// check if the position is valid or if the next node is NULL
    {
        return 0;
    }

    Position q = p->next; //store the next node which we want to pop in a temporary variable
    int x = q->data; // store the data which we want to pop to return it later
    p->next = q->next; //link the current node to the next node q->next which is the node not stored any data
    free(q); // free the temporary variable now 
    return x;
}

int PopLast(List *L)
{
    if (EmptyList(*L))
    {
        return 0;
    }
    Position p = *L;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    int x = p->next->data;
    free(p->next);// free the last node
    p->next = NULL; // set the next pointer of the last node to NULL
    return x;
}

int PopFirst(List *L)
{
    return PopAt(0, L);
}

int Len(List L)
{
    Position p = L->next;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

// Position Operator

Position FirstList(List L)
{
    return L->next;
}

Position LastList(List L)
{
    Position p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

Position Next(int i, List L)
{
    Position p = getPosition(i, L);
    return p->next;
}

Position previous(Position p, List L)
{
    Position q = L;
    while (q->next != NULL && q->next != p)
    {
        q = q->next;
    }
    return q;
}

Position locate(ElementType x, List L)
{
    Position p = L;
    while (p->next != NULL)
    {
        if (p->next->data == x)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Position getPosition(int i, List L)
{
    Position p = L;
    int j = 0;
    while (p->next != NULL && j < i)
    {
        j++;
        p = p->next;
    }
    return p;
}

ElementType getAt(int i, List L)
{
    Position p = getPosition(i, L);
    if (p->next == NULL)
    {
        printf("Invalid index!\n");
        exit(1);
    }
    return p->next->data;
}
