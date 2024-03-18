#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, n, t;
    cin >> t;
    vector<vector <int>> dp(15, vector<int>(15,0));

    for (int i = 0; i<t; ++i) {

        cin >> k >> n;
        
        for (int p = 1; p<=n; ++p) dp[0][p] = p;
        dp[1][1] = dp[0][1];
        for (int j = 1; j<=k;++j) {
            for (int p = 1; p <= n; ++p) {
                dp[j][p] = dp[j-1][p] + dp[j][p-1];
            }
        }
        cout << dp[k][n] << endl;

    }
}