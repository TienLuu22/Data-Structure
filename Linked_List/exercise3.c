#include <stdio.h>
#include "plistlib.h"

int a[] = {32, 51, 27, 83, 66, 11, 45, 75};

void appendList(int a[], int n, List *L)
{
    makeNullList(L);
    for (int i = 0; i < n; ++i)
    {
        append(a[i], L);
    }
}

void reverseList(int a[], int n, List *L)
{
    makeNullList(L);
    for (int i = n - 1; i >= 0; i--)
    {
        append(a[i], L);
    }
}

void bubbleSort(List *L)
{
    int len = Len(*L);
    for (int i = 0; i < len - 1; i++)
    {
        Position p = (*L)->next;
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (p->next->data < p->data)
            {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }
}

float average(List L)
{
    if (L == NULL || L->next == NULL)
        return 0.0;
    int sum = 0;
    int count = 0;
    Position p = FirstList(L);
  
    while (p != NULL)
    {
        sum += p->data;
        count++;
        p = p->next;
    }
    if (count == 0)
        return 0.0;
    return (float)sum / count;
}

int sumList(List L)
{
    if (L == NULL || L->next == NULL)
        return 0;
    Position p = FirstList(L);
    
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int maxList(List L)
{
    if (L == NULL || L->next == NULL)
        return 0;
    Position p = FirstList(L);
    
    int max = p->data;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int minList(List L)
{
    if (L == NULL || L->next == NULL)
        return 0;
    Position p = FirstList(L);
   
    int min = p->data;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

int main()
{
    List L1;
    List L2;

    appendList(a, sizeof(a) / sizeof(int), &L1);
    printf("List of Element:\n");
    PrintList(L1);

    reverseList(a, sizeof(a) / sizeof(int), &L2);
    printf("Reverse List of Element:\n");
    PrintList(L2);

    InsertAt(22, 3, &L1);
    printf("List after insert element 22 at position 3:\n");
    PrintList(L1);

    bubbleSort(&L1);
    printf("List after bubbleSort:\n");
    PrintList(L1);

    printf("Sum of list: %d\n", sumList(L1));
    printf("Average of list: %.2f\n", average(L1));
    printf("Max of list: %d\n", maxList(L1));
    printf("Min of list: %d\n", minList(L1));

    return 0;
}