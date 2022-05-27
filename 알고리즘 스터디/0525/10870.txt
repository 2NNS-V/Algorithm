#include <stdio.h>

int Fibonacci(int n) {
	if (n < 2) return n;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
	int n;
	scanf_s("%d", &n);
	printf("%d", Fibonacci(n));
}