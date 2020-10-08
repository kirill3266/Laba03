#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

	
 int minA(double *x) {
	double x1 = *x;
	printf("x1= %fl\n", x1);
	int	 a=(int)x1;
	printf("a= %d\n", a);
	double b=x1-a;
	b = b >= 0 ? b : b * (-1);
	printf("b= %fl\n", b);
	double min=b;
	printf("min= %fl\n\n", min);
	int minindex = 0;
	int i = 1;
	while ((*(x+i) < 0) || (*(x+i) > 0.0000001) || (i == 999)) {
		double x1 = *(x+i);
		printf("x11= %fl\n", x1);
		a = (int)x1;
		printf("a1= %d\n", a);
		double b = x1 - a;
		b = b >= 0 ? b : b * (-1);
		printf("b1= %fl\n\n", b);
		if (b < min) {
			min = b;
			printf("min1= %fl\n", min);
			minindex = i;
			printf("minindex1= %d\n\n", minindex);
		}
		i++;
	}
	return minindex;	
}

 int main() {
	 printf("Vvedite kol-vo elementov: ");
	 double A[1000] = { 1 };
	 int i = -1;
	 do {
		 i++;
		 printf("A[%d]= ", i);
		 scanf("%lf", &A[i]);
	 } while ((A[i] < 0) || (A[i] > 0.0000001) || (i == 999));
	 printf("\n");
	 int result = minA(A);
	 printf("result= %d\n", result);
	 printf("Min chislo: %lf", A[result]);
	return 0; 
}