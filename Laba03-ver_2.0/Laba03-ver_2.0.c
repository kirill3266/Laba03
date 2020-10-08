#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�������, ���������� ������ ������� ������� �� ��� �����
double* tcel(double* x,int n) {
	//�������� ����� ��� ������� 
	double* p_copy = (double*)malloc(n * sizeof(double));
	//������ ��������� ������� �� �� �����
	for (int i = 0; i < n; i++) {
		*(p_copy+i) = (int)*(x + i);
		*(x + i) = *(x + i) -*(p_copy+i);
		*(x + i) = *(x + i) >= 0 ? (*(x + i)) : (*(x + i) * (-1));
	}
	//������������ ������ �������-�����
	free(p_copy);
}

//���������� ������������ �������� �������
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
	//�������� ���-�� ���������
	int n;
	do {
		printf("Vvedite kol-vo elementov: ");
		scanf("%d", &n);
	} while (n <= 0);

	//��������� ������ ��� ������
	double* p = (double*)malloc(n * sizeof(double));

	//������������� �������
	for (int i = 0; i < n; i++) {
		printf("Vvedite element %d: ", i);
		scanf("%lf",&(*(p + i)));
		printf("Element %d: %f\n", i, *(p + i));
	}
		
	//������������� ������� ������ ��������� ������� �� �� �����
	tcel(p, n);

	//���������
	printf("Result: %lf", *(p + minarr(p, n)));
	//������������ ������
	free(p);
return 0;
}
