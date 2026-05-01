#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
    int ch_size = (arr.size() + 1) / 2;
    
    vector<vector<int>> min_dp(ch_size, vector<int> (ch_size, INT_MAX));
    vector<vector<int>> max_dp(ch_size, vector<int> (ch_size, INT_MIN));
    
    vector<int> number;
    
    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            min_dp[j][j] = stoi(arr[i]);
            max_dp[j][j] = stoi(arr[i]);
            j++;
        }
    }
    
    for (int len = 2; len <= ch_size; len++) {
        for (int i = 0; i <= ch_size - len; i++) {
            int j = i + len - 1;
            
            for (int k = i; k < j; k++) {
                string op = arr[k * 2 + 1];
                if (op == "+") {
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] + max_dp[k + 1][j]);
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] + min_dp[k + 1][j]);
                }
                else {
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] - min_dp[k + 1][j]);
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] - max_dp[k + 1][j]);
                }
            }
        }
    }
    
    answer = max_dp[0][ch_size - 1];
    return answer;
}