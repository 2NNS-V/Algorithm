#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[1001][3];
int input[1001][3];

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}


int main() {
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
	}

	dp[0][0] = input[0][0];
	dp[0][1] = input[0][1];
	dp[0][2] = input[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + input[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + input[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + input[i][2];
	}

	printf("%d", min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]));
}