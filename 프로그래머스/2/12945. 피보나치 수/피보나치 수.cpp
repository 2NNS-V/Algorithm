#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> dp(n+1, 0);
    
    if (n < 2) {
        return n;
    }
    
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    
    return dp[n] % 1234567;
}