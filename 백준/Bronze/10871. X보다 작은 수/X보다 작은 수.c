#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, X, a;
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		if (X > a) printf("%d ", a);
	}
}