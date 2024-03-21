#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t; cin >> t;
	vector<int> arr;
	vector<int> dp(12, 0);

	dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 4;

	for (int i = 0; i < t;i++) {
		int n; cin >> n;
		for (int j =4;j <= n;j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[n] << "\n";

	}

}