#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	int n;
	cin >> n;

	int dp[1001] = { 0, };
	int arr[1001];
	vector<int> LIS[1001];
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		LIS[i].push_back(arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				LIS[i].clear();
				LIS[i] = LIS[j];
				LIS[i].push_back(arr[i]);
			}
		}
		if (ans.size() < LIS[i].size()) ans = LIS[i];
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	} 
}
