#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alistlib.h"

Position binarySearch(ElementType x, List L)
{
    Position low = first(L);
    Position high = endList(L) - 1;
    while (low <= high)
    {
        Position mid = (low + high) / 2;
        if (L.element[mid] == x)
            return mid;
        else if (L.element[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return endList(L);
}

int main(void)
{
    List L;
    makeNullList(&L);

    /* build the sorted list */
    ElementType a[] = {11, 22, 27, 32, 45, 51, 66, 75, 83};
    for (int i = 0; i < 9; i++)
        append(a[i], &L);

    /* print the list */
    printList(L); /* prints: 11 22 27 32 45 51 66 75 83 */
    /* search examples */
    ElementType queries[] = {22, 90};
    for (int i = 0; i < 2; i++)
    {
        Position p = binarySearch(queries[i], L);
        int report = (p == endList(L) ? -1 : p);
        printf("%d located at position %d\n", queries[i], report);
    }

    return 0;
}