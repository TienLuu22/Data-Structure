#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

int main(){
	Polynomial p1, p2 ,Sum, Derve_1, Derve_2;
	
	printf("enter first polynomial:\n");
	InputPoly(&p1);
	
	
	printf("enter second polynomial:\n");
	InputPoly(&p2);
	
	Sum = AddPoly(p1, p2);
	Derve_1 = Derivative(p1);
	Derve_2 = Derivative(p2);
	
	
	printf("first Poly:\n");
	PrintPoly(p1);
	printf("\n");
	
	printf("second Poly:\n");
	PrintPoly(p2);
	printf("\n");
	
	printf("Sum of two poly:\n");
	PrintPoly(Sum);
	printf("\n");
	
	printf("Derivative\n");
	printf("\n");
	PrintPoly(Derve_1);
	printf("\n");
	PrintPoly(Derve_2);
	
	return 0;
	
	
}