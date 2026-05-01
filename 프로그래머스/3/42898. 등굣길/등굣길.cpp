#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[2] = {0, 1};
int dy[2] = {1, 0};


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0)); // dp에 경로
    
    dp[1][1] = 1;
    for (auto p: puddles) {
        dp[p[1]][p[0]] = -1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    
    answer = dp[n][m] % 1000000007;
    
    return answer;
}