#include <iostream>

using namespace std;

int n, k;
int A[10];

int main() {
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] <= k) {
            ans += k / A[i];
            k = k % A[i];
        }
    }
    cout << ans;
}