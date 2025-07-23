#ifndef polynomial
#define polynomial

#define MaxSize 10000

typedef struct{
	int factor;
	int exponent;
}Element;

typedef struct{
	Element term[MaxSize];
	int Size; 
}Polynomial;

void InputPoly(Polynomial *poly);
void PrintPoly(Polynomial poly);
Polynomial AddPoly(Polynomial p1, Polynomial p2);
Polynomial Derivative(Polynomial poly);

#endif