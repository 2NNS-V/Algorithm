#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int> > dp(land.size(), vector<int>(4, 0));
    for (int i = 0; i < 4; i++) {
        dp[0][i] = land[0][i];
    }
    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int prev = 0;
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
                prev = max(prev, dp[i-1][k]);
            }
            dp[i][j] = prev + land[i][j];
        } 
    }
    
    for (int i = 0; i < 4; i++) {
        answer = max(answer, dp[land.size() - 1][i]);
    }

    return answer;
}