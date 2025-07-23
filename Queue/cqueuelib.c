#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cqueuelib.h"

void initQueue(Queue *q)
{
    Node *sentinel = (Node *)malloc(sizeof(Node));
    sentinel->next = NULL;
    q->front = sentinel;
    q->rear = sentinel;
}

void enQueue(Queue *q, ElementType x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    q->rear->next = newNode;
    q->rear = newNode;
}

ElementType deQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    Node *start = q->front->next;
    ElementType value = start->data;
    q->front->next = start->next;

    if (q->rear == start)
    {
        q->rear = q->front; // If the queue becomes empty, reset rear to front
    }
    free(start);
    return value;
}

ElementType peek(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty!\n");
        return 0; 
    }
    else
    {
        return q->front->next->data; // Return the data of the front node
    }
}

int isEmpty(Queue *q)
{
    return q->front->next == NULL;
}

int size(Queue q)
{
    int count = 0;
    Node *current = q.front->next;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

