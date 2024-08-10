#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> dp(k+1);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1; // * 아무것도 선택하지 않은 경우의 수
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] += dp[j - arr[i]]; // * j-arr[i]번째 dp값에 j번째 arr[i]를 선택한 경우의 수를 더함
        }
    }
    
    cout << dp[k] << "\n";
    return 0;
}