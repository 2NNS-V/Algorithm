#include <stdio.h>

int N, S;
int num[21], sum, cnt=0;

void Sum(int i, int sum) {
	sum += num[i];
	if (i >= N) return;
	if (sum == S) cnt++;
	Sum(i + 1, sum - num[i]);
	Sum(i + 1, sum);
	
}


int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	Sum(0, 0);
	printf("%d", cnt);
	return 0;
}