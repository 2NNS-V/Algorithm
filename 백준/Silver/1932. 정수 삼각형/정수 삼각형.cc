#include <iostream>
#include <algorithm>

#define MAX 501
using namespace std;

long long arr[MAX][MAX] = {0,};
long long dp[MAX][MAX] = {0,};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1 ; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) {
                dp[i][j] = arr[i][j] + dp[i-1][j];
            }
            else if (j == i) { 
                dp[i][j] = arr[i][j] + dp[i-1][j-1];
            }
            else {
                dp[i][j] = arr[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }


    sort(dp[n-1], dp[n-1]+n);
    cout << dp[n-1][n-1];
}