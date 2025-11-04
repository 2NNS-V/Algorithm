#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, t;

int main() {
    cin >> t;
    
    while (t--) {
        cin >> n;
        vector<int> arr;
        
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            arr.push_back(tmp);
        }
        
        long long ans = 0;
        int max_value = -1;
        
        for (int i = n - 1; i >= 0; i--) {
            max_value = max(max_value, arr[i]);
            ans += max_value - arr[i];
        }
        
        cout << ans << endl;
    }
}