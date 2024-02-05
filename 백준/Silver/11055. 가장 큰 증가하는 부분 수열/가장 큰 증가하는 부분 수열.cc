#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	int n;
	cin >> n;

	int dp[1001] = { 0, };
	int arr[1001];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max = 0;

	for (int i = 0; i < n; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) dp[i] = dp[j] + arr[i];
		}
		if (max < dp[i]) max = dp[i];
	}

	cout << max;
}