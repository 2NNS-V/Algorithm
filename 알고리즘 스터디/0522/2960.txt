#include <stdio.h>
#define max 1001

int main() {
	int N, K, a[max], cnt=0;
	scanf_s("%d %d", &N, &K);

	for (int i = 2; i <= N; i++) { // 배열 초기화
		a[i] = i;
	}
	
	for (int i = 2; i <= N; i++) {
		if (a[i] == 0) { // 이미 지운 경우
			continue;
		}
		for (int j = i; j <= N; j += i) { // i의 배수를 모두 지움
			if (a[j] != 0) {
				a[j] = 0;
				cnt++;
			}
			if (cnt == K) printf("%d", j);
		}
	}

}