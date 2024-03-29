#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> dp(16,0);
int t[16] = {0,}; int p[16]={0,};
int main() {
    int n; cin >> n;
    
    for (int i=0;i<n;i++) {
        cin >> t[i] >> p[i];
    }

    int max_value = 0;
    for (int i = 0; i <= n;i++) {
        dp[i] = max(max_value, dp[i]);
        // 퇴사 날짜를 지나는 경우
        if (t[i] + i <= n) {
            dp[t[i] + i] = max(dp[t[i] + i], p[i] + dp[i]);
        }
        max_value = max(max_value, dp[i]);
    }
    cout << max_value;

}