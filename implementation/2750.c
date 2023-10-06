#include <stdio.h>

int main(void) {
	int n, num[1000] = { 0, }, tmp;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		for (int j = 0; j < i;j++) {
			if (num[i] < num[j ]) {
				tmp = num[j];
				num[j] = num[i];
				num[i] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", num[i]);
	}

	return 0;
}