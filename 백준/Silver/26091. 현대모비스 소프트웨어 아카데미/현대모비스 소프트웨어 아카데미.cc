#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int start = 0, end = n - 1;
    int cnt = 0;
    while (start < end) {
        int sum = arr[start] + arr[end];

        if (sum >= m) {
            cnt++;
            start++;
            end--;
        }
        else {
            start++;
        }
    }
    cout << cnt;
}