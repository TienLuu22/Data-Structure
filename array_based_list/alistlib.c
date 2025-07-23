#include <stdio.h>
#include "alistlib.h"

bool emptyList(List L){
	return L.Size == 0;
}
bool fullList(List L){
	return L.Size == MaxSize;
}

void makeNullList(List *L){
	 L->Size = 0;	 
}
void readList(List *L){
	 int n;
	 int i;
	 ElementType x;
	 makeNullList(L);
	 do{
	 	printf("Number of Element:");
	 	scanf("%d", &n);
	 }while (n < 1 || n > MaxSize);
	 
	 for(i=0; i < n; i++){
	 	printf("Input element[%d]: ", i+1);
	 	scanf("%d", &x);
	 	append(x,L);
	 }
}

void printList(List L){
	int i;
	for(i= 0;i < L.Size;++i){
		printf("%d ",L.element[i]);
	}
	printf("\n");
}

void setAt(Position p, ElementType x, List *L){
	if(p >= 0 && p < L->Size){
		L->element[p] = x;
	}else{
		printf("vi tri khong hop le!\n");
		}
}

void insertAt(Position p, ElementType x, List *L){
	int i;
	if(fullList(*L) ||p < 0 || p > L->Size){
		printf("Khong the chen phan tu");
		return;
	}
	for(i = L->Size; i > p; --i){
		L->element[i] = L->	element[i-1];
	}
	L->	element[p] = x;
	L->Size++;

}

void insertFirst(ElementType x, List *L){
	insertAt(0,x,L);
}

void append(ElementType x, List *L){
	if(!fullList(*L)){
		L->element[L->Size++] = x;
	}
	else{
		printf("danh sach da day");
	}
}

	void Bubblesort(List *L){
		
		int i,j;
		int n = Len(*L);
		for(i = 0; i < n-1; i++){	
			
			Position p1 = first(*L);
			
			for(j=0; j < n-1-i;j++){
				Position p2 = next(p1,*L);
				ElementType a = GetAt(p1,*L);
				ElementType b = GetAt(p2,*L);
			
			if(a > b){
				setAt(p1, b, L);
				setAt(p2, a, L);
			}
			p1 = next(p1,*L);
			}		
		}
		
	}

int Len(List L){
	return L.Size;
}


ElementType GetAt(Position p, List L){
	if(p >= 0 && p < L.Size){
		return L.element[p];
	}
	else{
		printf("vi tri khong hop le");
		return -1;
	}
}
ElementType popAt(Position p, List *L){
	if(emptyList(*L) || p < 0 || p >= L->Size){
		printf("vi tri khong hop le");
		return -1;
	}
	ElementType x = L->element[p];
	int i;
	for(i = p ;i < L->Size-1; ++i){
		L->element[i] = L->element[i+1];
	}
	L->Size--;
	return x;
}
ElementType popFirst(List *L){
	return popAt(0,L);
}

ElementType popLast(List *L){
	if(!emptyList(*L)){
		return L->element[--L->Size];
	}
	else
	{
		printf("danh sach rong khong the xoa");
		return -1;
	}
}

Position first(List L){
	return 0;
}
Position endList(List L){
	return L.Size;
}
Position locate(ElementType x, List L)
{
	int i;
	for(i = 0; i < L.Size; ++i){
		if(L.element[i] == x){
			return i;
		}
	}
	return -1;
}

Position next(Position p, List L)
{
	if(p >= 0 && p < L.Size-1){
		return p+1;
	}
	else{
		return endList(L);
	}
}
Position previous(Position p, List L){
	if(p > 0 && p <= L.Size){
		return p - 1;
	}
	else{
		return -1;
	}
}
 