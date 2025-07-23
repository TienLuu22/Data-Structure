#ifndef CQUEUELIB_H
#define CQUEUELIB_H

typedef int ElementType;

typedef struct NodeTag
{
    ElementType data;
    struct NodeTag *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;

} Queue;

void initQueue(Queue *q);
void enQueue(Queue *q, ElementType x);
ElementType deQueue(Queue *q);
int isEmpty(Queue *q);
int size(Queue q);
ElementType peek(Queue *q);

#endif // CQUEUELIB_H
