#include <iostream>

using namespace std;

int t, n, m;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long ans = 1;
        cin >> n >> m;

        // combination
        if (n == 0 || n == m) ans = 1;
        else if (n == 1) ans = m;
        else {
            for (int i = 0; i < n; i++) {
                ans *= (m - i);     // Multiply numerator
                ans /= (i + 1);    // Divide by denominator
            }
        }
        
        
        cout << ans << endl;
    }
}