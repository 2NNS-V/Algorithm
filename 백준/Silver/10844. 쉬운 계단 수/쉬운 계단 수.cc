#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<unsigned long long>> dp(101, vector<unsigned long long>(10, 0));
    
    dp[1][0]=0;
    for (int i=1;i<10;i++) {
        dp[1][i] = 1;
    }

    for (int i=2;i<=n;i++) {
        for (int j =0; j< 10;j++) {
            if ( j == 0) dp[i][0] = dp[i-1][1];
            else if (j ==9) dp[i][9] = dp[i-1][8];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }
    unsigned long long result = 0;
    for (int i=0;i<10;i++) result = (result+dp[n][i]) % 1000000000;
    cout<<result;

}