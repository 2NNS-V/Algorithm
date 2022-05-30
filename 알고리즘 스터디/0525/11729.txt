#include <stdio.h>
#include <math.h>

void moves(int n, char start, char dest, char tmp) {
	if (n == 1) printf("%d %d\n", start, dest);
	else {
		moves(n - 1, start, tmp, dest);
		printf("%d %d\n", start, dest);
		moves(n - 1, tmp, dest, start);
	}
}

int main(void) {
	int n, cnt;
	scanf("%d", &n);
	cnt = pow(2, n) - 1;
    printf("%d\n", cnt);
	moves(n, 1, 3, 2);
}