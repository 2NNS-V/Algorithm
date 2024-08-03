#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 

using namespace std;

vector <pair<int,int>>arr;

int main() {
    int n, k; // n : 물건 개수, k : 가방의 최대 무게
    int w, v; // w : 가방의 무게, v : 가방의 가치

    arr.push_back({0,0});
    cin >> n >> k;
    for (int i = 0; i<n; i++) {
        cin >> w >> v;
        arr.push_back({w, v});
    }

    // * DP 테이블 순회
    int dp[101][100005] = {0,};
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= k;j++) {
            int weight = arr[i].first;
            int value = arr[i].second;

            if (weight <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value);
            } 
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][k];
    return 0;
}