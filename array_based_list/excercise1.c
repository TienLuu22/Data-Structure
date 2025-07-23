#include <stdio.h>
#include "alistlib.h"


void SortAscending(List *L){
	int i,j;
		for(i = 0; i < L->Size-1;++i){
			for(j = i+1; j < L->Size; ++j){
				if(L->element[i] > L->element[j]){
					ElementType temp = L->element[i];
					L->element[i]= L->element[j];
					L->element[j]= temp;
				}
			}
		}
	}
	
int main() {
	List myList;
	
	readList(&myList);
	printf("danh sach da duoc nhap\n");
	printList(myList);
	
	Bubblesort(&myList);
	printList(myList);
	
	return 0;
}