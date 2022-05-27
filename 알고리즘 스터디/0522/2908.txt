#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);

	int A, B;
	A = (a % 10) * 100 + ((a % 100) / 10) * 10 + a / 100;
	B = (b % 10) * 100 + ((b % 100) / 10) * 10 + b / 100;

	if (A > B)
		printf("%d", A);
	else printf("%d", B);
}