#include <iostream>
#define MAX 101
using namespace std;

long long dp[MAX] = {0,};

int main() {
    int t, n;
    cin >> t;
    
    for (int i = 0; i<t; i++) {
        cin >> n;
         
        if (n <= 2) {
            cout << 1 << endl;
            continue;
        }
       
        dp[1] = 1; dp[2] = 1;
        for (int k = 3; k <=n; k++) {
            dp[k] = dp[k-2] + dp[k-3];
        }
        cout << dp[n] << endl;
    }
    return 0;
}