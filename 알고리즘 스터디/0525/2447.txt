#include <stdio.h>

int n, x, y;

void Star(int x, int y, int n) {
	if ((x / n) % 3 == 1 && (y / n) % 3 == 1)
		printf(" ");
	else {
		if (n / 3 == 0) printf("*");
		else Star(x, y, n / 3);
	}
}


int main(void) {
	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Star(i, j, n);
		}
		printf("\n");
	}
}