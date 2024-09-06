#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;

    long long sum = 0;
    vector<pair <long long ,long long>> arr;
    for (int i = 0; i < n; i++) {
        long long x, a;
        cin >> x >> a;
        sum += a;
        arr.push_back({x, a});
    }
    sort(arr.begin(), arr.end());

    long long ans = 0;
    for (int i = 0; i < n ; i++) {
        ans += arr[i].second;
        if (ans >= (sum + 1) / 2) {
            cout << arr[i].first;
            break;
        }
    }
}