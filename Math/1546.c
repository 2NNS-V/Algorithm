#include <stdio.h>

int main(void) {
	int n, score, max=0, sum=0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &score);
		sum += score;
		if (score > max) max = score;
	}
	printf("%f", 100.0 * sum / n / max);
}