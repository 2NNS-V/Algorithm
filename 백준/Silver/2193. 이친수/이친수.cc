#include <iostream>
#define MAX 91
using namespace std;

long long dp[MAX] = {0,};

int main(){
    int n;
    cin >> n;
    
    dp[1] = 1; 
    for (int i = 2; i <= n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;
    return 0;
}