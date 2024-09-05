#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> cnt;
    for (int i = 0; i<n; i++) {
        int start, end;
        cin >> start >> end;
        cnt.push_back({start, end});
    }

    sort(cnt.begin(), cnt.end());

    int ans = 0, next = 0;
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i].first > next) {
            next = cnt[i].first;
        }

        while (cnt[i].second > next) {
            ans++;
            next += l;
        }
    }

    cout << ans;
}