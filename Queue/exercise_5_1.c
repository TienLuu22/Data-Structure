#include <stdio.h>
#include <stdlib.h>
#include "cqueuelib.h"
#include "astacklib.h"

int main()
{
    Stack S;
    Stack clone;
    Queue Q;

    initStack(&clone);
    initStack(&S);
    initQueue(&Q);

    int value, n;
    printf("Enter numbers of element to push: \n");
    scanf("%d", &n);

    printf("Enter a value to push onto the stack: \n");
    for (int i = 0; i < n; i++)
    {
        printf("enter value %d: ", i + 1);
        scanf("%d", &value);
        push(value, &S);
        push(value, &clone); // Clone the stack
    }

    printf("Stack before reverse: \n");

    for (int i = 0; i <= clone.top; i++)
    {
        printf("%d ", clone.data[i]);
    }

    printf("\n");

    while (S.top != -1)
    {
        enQueue(&Q, pop(&S));
    }

    printf("Stack after reverse by queue: \n");
    while (!isEmpty(&Q))
    {
        printf("%d ", deQueue(&Q));
    }
    printf("\n");

    return 0;
}