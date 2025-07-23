#include <stdio.h>
#include "cqueuelib.h"

#define CAPACITY 100

void produce(Queue *warehouse, int order_id)
{
    if (size(*warehouse) >= CAPACITY)
    {
        printf("Cannot receive order now .\n");
    }
    else
    {
        enQueue(warehouse, order_id);
        printf("order %d has been receive.\n", order_id);
    }
    printf("\n");
}

void consume(Queue *warehouse)
{
    if (isEmpty(warehouse))
    {
        printf("There no order drink counter.\n");
    }
    else
    {
        ElementType order = deQueue(warehouse);
        printf("order %d has been finished and served.\n", order);
    }
}

int main()
{
    Queue drinkCounter;
    initQueue(&drinkCounter);
    int numberOfOrder, OrderID;

    printf("Enter the number of order : ");
    scanf("%d", &numberOfOrder);
    printf("\n");

    for (int i = 0; i < numberOfOrder; i++)
    {
        printf("Enter ID of order %d: ", i + 1);
        scanf("%d", &OrderID);
        produce(&drinkCounter, OrderID);
    }

    printf("Enter number of finished orders:\n");
    
    int finishedOrders;
    scanf("%d", &finishedOrders);

    for(int i = 0; i < finishedOrders; i++)
    {
        consume(&drinkCounter);
    }
    printf("\n");

    printf("remaining order in the queue: %d\n", size(drinkCounter));
    printf("\n");
    printf("next order to be served: %d\n", peek(&drinkCounter));

    return 0;
}
