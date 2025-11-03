#include <iostream>
#include <algorithm>
#include <climits>

int weight[100001];

using namespace std;

int main() {
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    sort(weight, weight + n);

    int max = -INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (max < weight[i] * (n - i)) 
            max = weight[i] * (n - i);
    }
    cout << max;
    // 5
    // 2 10 8 5 7 -> 2, 5, 7, 8, 10
    // 2, 5, 7, 8 10 : 2 * 5 = 10
    // 5, 7, 8, 10 : 5 * 4 = 20
    // 7, 8, 10: 7 * 3 = 21
    // 8, 10: 8 * 2 = 16
    // 10: 10
}