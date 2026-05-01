#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int tri_size = triangle.size();
    
    vector<vector<int>> dp(tri_size, vector<int> (tri_size , 0));
    
    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[1][0] + dp[0][0];
    dp[1][1] = triangle[1][1] + dp[0][0];
    
    for (int i = 2; i < tri_size; i++) {
        dp[i][0] = triangle[i][0] + dp[i-1][0];
        for (int j = 1; j < triangle[i].size(); j++) {
            dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    
    for (int i = 0; i < dp[tri_size - 1].size(); i++) {
        if (dp[tri_size - 1][i] > answer) 
            answer = dp[tri_size - 1][i];
    }
    return answer;
}