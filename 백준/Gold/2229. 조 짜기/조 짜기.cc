#include <iostream>
#include <algorithm>

#define MAX 1001

using namespace std;

int arr[MAX] = {0,};
int dp[MAX] = {0,};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // dp[i] : i명으로 구성할 떄 최댓값
    for (int i=0;i<n;i++) {
        int maxValue = arr[i];
        int minValue = arr[i];

        for (int j = i; j >= 0; j-- ) {
            maxValue = max(maxValue, arr[j]);
            minValue = min(minValue, arr[j]);

            dp[i+1] = max(dp[i+1], dp[j] + maxValue - minValue);
        }
    }

    cout << dp[n] << "\n";

}