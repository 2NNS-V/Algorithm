#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        int x, y; 
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }

    sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}
