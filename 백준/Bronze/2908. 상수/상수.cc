#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int A, B;
	A = (a % 10) * 100 + ((a % 100) / 10) * 10 + a / 100; // a의 100의 자리수와 1의 자리수를 바꿈
	B = (b % 10) * 100 + ((b % 100) / 10) * 10 + b / 100; // b의 100의 자리수와 1의 자리수를 바꿈

	if (A > B)
		printf("%d", A);
	else printf("%d", B);
}