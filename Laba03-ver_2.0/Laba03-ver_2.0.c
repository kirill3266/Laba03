#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//функция, заменяющая каждый элемент массива на его дробь
double* tcel(double* x,int n) {
	//создание копии для массива 
	double* p_copy = (double*)malloc(n * sizeof(double));
	//замена элементов массива на их дроби
	for (int i = 0; i < n; i++) {
		*(p_copy+i) = (int)*(x + i);
		*(x + i) = *(x + i) -*(p_copy+i);
		*(x + i) = *(x + i) >= 0 ? (*(x + i)) : (*(x + i) * (-1));
	}
	//освобождение памяти массива-копии
	free(p_copy);
}

//Вычисление минимального элемента массива
int minarr(double* x, int n) {
	double min= *x;
	int minind = 0;
	for (int i = 0; i < n; i++) {
		if (*(x + i) < min) {
			min = *(x + i);
			minind = i;
			printf("Ind: %lf", min);
		}
	}
		return minind;
}

int main() {
	//Введение кол-ва элементов
	int n;
	do {
		printf("Vvedite kol-vo elementov: ");
		scanf("%d", &n);
	} while (n <= 0);

	//Выделение памяти под массив
	double* p = (double*)malloc(n * sizeof(double));

	//Инициализация массива
	for (int i = 0; i < n; i++) {
		printf("Vvedite element %d: ", i);
		scanf("%lf",&(*(p + i)));
		printf("Element %d: %f\n", i, *(p + i));
	}
		
	//Использование функции замены элементов массива на их дроби
	tcel(p, n);

	//результат
	printf("Result: %lf", *(p + minarr(p, n)));
	//освобождение памяти
	free(p);
return 0;
}
