#include <stdio.h>
#include "cqueuelib.h"
#include "astacklib.h"

int main()
{
    Stack S;
    Queue Q;
    Queue clone;

    initQueue(&clone);
    initStack(&S);
    initQueue(&Q);

    int value, n;

    printf("Enter number of elements to enqueue: \n");
    scanf("%d", &n);

    printf("Enter values to enqueue into the queue: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Value %d: ", i + 1);
        scanf("%d", &value);
        enQueue(&Q, value);
        enQueue(&clone, value);
    }
    printf("\n");

    printf("Queue before reverse:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", deQueue(&clone));
    }
    printf("\n");

    while (!isEmpty(&Q))
    {
        push(deQueue(&Q), &S);
    }

    printf("Queue after reverse by stack:\n");

    while (S.top != -1)
    {
        printf("%d ", pop(&S));
    }
    printf("\n");
    return 0;
}