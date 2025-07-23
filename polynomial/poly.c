#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

void InputPoly(Polynomial *poly)
{
	int i;
	
	printf("Please enter a polynomial:\n");
	scanf("%d", &(poly->Size));
	
	
	for(i = 0; i < poly->Size;++i){
		printf("Enter factor and exponent:\n");
		scanf("%d %d", &(poly->term[i].factor),&(poly->term[i].exponent));
	}
	
}


void PrintPoly(Polynomial poly)
{
	int i;
	
	for(i = 0; i < poly.Size;++i){
		printf("%dx^%d",(poly.term[i].factor), (poly.term[i].exponent) );
		if(i != poly.Size-1){
			printf("+");
		}
	}
	printf("\n");
}


Polynomial AddPoly(Polynomial p1, Polynomial p2)
{
	Polynomial result;
	result.Size = 0;
	
	int i = 0 ,j = 0;
	while((i < p1.Size) && (j < p2.Size))
	{
		if(p1.term[i].exponent > p2.term[j].exponent )
		{
			result.term[result.Size++] = p1.term[i++];
		}
		else if (p1.term[i].exponent < p2.term[j].exponent)
		{
			result.term[result.Size++] = p2.term[j++];
		}
		else
		{
		 	int sum = p1.term[i].factor + p2.term[j].factor;
		 	if(sum != 0)
		 	{
		 		result.term[result.Size].factor = sum;
		 		result.term[result.Size].exponent = p1.term[i].exponent;
		 		result.Size++;
			 }
			 i++, j++;
		}
	}
	while(i< p1.Size) result.term[result.Size++]= p1.term[i++];
	while(j< p2.Size) result.term[result.Size++]= p2.term[j++];
	
	return result;
}


Polynomial Derivative(Polynomial poly)
{
	Polynomial result;
	result.Size = 0;
	
	int i;
	
	for(i = 0; i < poly.Size; i++){
		if(poly.term[i].exponent != 0){
			result.term[i].factor = (poly.term[i].factor) * (poly.term[i].exponent);
			result.term[i].exponent = poly.term[i].exponent - 1;
			result.Size++;
		}
	}
	return result; 
}
