#include <stdio.h>

int main() {
	int n, k, x[1000];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	for (int i = 0; i < n; i++) { // 내림차순
		for (int j = i + 1; j < n; j++) {
			if (x[i] < x[j]) {
				int tmp = x[j];
				x[j] = x[i];
				x[i] = tmp;
			}
		}
	}
	printf("%d", x[k - 1]);
}