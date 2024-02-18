#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> arr[10001];

int main() {
	int n, d;
	cin >> n >> d;
	
	vector<int> dp(d + 1, 100001);

	int from, to, dis;
	for (int i = 0; i < n; i++) {
		cin >> from >> to >> dis;
		arr[to].push_back({ from,dis });
	}

	dp[0] = 0;
	for (int i = 1; i <= d; i++) {
		if (arr[i].size() == 0) dp[i] = dp[i - 1] + 1;
		else {
			for (auto v : arr[i]) {
				dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[v.first] + v.second));
			}
		}
	}
	cout << dp[d] << "\n";

}