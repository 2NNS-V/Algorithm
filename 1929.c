#include <stdio.h>

int isPrime(int a) {
	if (a < 2) return -1; // 소수 아님
	for (int i = 2; i*i <= a; i++) {
		if (a % i == 0) {
			return -1; // 소수 아님
		}
	}
	return 0; // 소수
}

int main() {
	int m, n;
	scanf_s("%d %d", &m, &n);

	while (m <= n) {
		if (isPrime(m) == 0) printf("%d\n", m);
		m++;
	}
}