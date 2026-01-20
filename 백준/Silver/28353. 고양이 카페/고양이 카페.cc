#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> weights(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());


    // 고양이 2마리를 데리고 있으면 됨
    int start = 0, end = n - 1;
    int sum = 0, cnt = 0;
    while (start < end) {
        int sum = weights[start] + weights[end];

        if (sum > k) {
            end--;
        }

        else {
            start++;
            end--;
            cnt++;
        }
    }
    cout << cnt;
}