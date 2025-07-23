#ifndef ASTACKLIB_H
#define ASTACKLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MaxSize 10000
#define ERROR -1

typedef int ElementType;

typedef struct
{
    ElementType data[MaxSize];
    int top;
} Stack;

void initStack(Stack *Ps)
{
    Ps->top = -1;
}
void push(ElementType x, Stack *Ps)
{
    if (Ps->top < MaxSize - 1)
    {
        Ps->top++;
        Ps->data[Ps->top] = x;
    }
    else
    {
        fprintf(stderr, "Stack overflow\n");
    }
}
ElementType pop(Stack *Ps)
{
    if (Ps->top == -1)
    {
        fprintf(stderr, "Stack underflow\n");
        return ERROR;
    }
    ElementType x = Ps->data[Ps->top];
    Ps->top--;
    return x;
}
#endif // ASTACKLIB_H