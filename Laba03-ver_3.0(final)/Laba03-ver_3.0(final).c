#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//переменна€, содержаща€ минимальное значение
double mina = 1;
//переменна€, обозначающа€ индекс цикла for
int i = 0;
//переменна€, содержаща€ индекс минимального  элемента
int index = 0;

//функци€, замен€юща€ значение введЄнной переменной на еЄ дробную часть
void tcel(double* x) {
	double tcel =(int) *x;
	printf("Tcel: %lf\n", tcel);
	*x -=tcel;
	printf("X posle tcel: %lf\n ", *x);
	*x = (*x >= 0) ? (*x) : ((*(x)) * (-1));
	printf("X posle proverki uslovia: %lf\n\n", *x);
}

//функци€,провер€юща€ значение минимума и вывод€ща€ на экран этот минимум
int minarr(double* x,double*p) {
	if (*x <= mina) {
		mina = *x;
		index = i;
		printf("Minimum: %lf\n\n", *(p + index));
	}
	else printf("Minimum: %lf\n\n", *(p + index));
}


int main() {

	//¬ведение кол-ва элементов
	int n;
	do
	{
		printf("Vvedite kol-vo elementov: ");
		scanf("%d", &n);
	} while (n <= 0);

	//создание переменной, в которую вводитс€ число
	double x;

	//создание массива, в который занос€тс€ все введЄнные числа
	double* p = (double*)malloc(n * sizeof(double));

	//создание цикла, с каждым разом провер€ющего услови€
	for (;i<n;i++){
		printf("Vvodite elementi. 0 to exit: ");
		scanf("%lf", &x);
		printf("Vvedennoe chislo: %lf\n\n", x);
		if (x == 0) {
			printf("Exiting...\n");
			 break;
		 } 
		*(p + i) = x;
		tcel(&x);
		minarr(&x,p);
	}
	
	//освобождение пам€тии, выделенной под массив
		free(p);
	return 0;
}