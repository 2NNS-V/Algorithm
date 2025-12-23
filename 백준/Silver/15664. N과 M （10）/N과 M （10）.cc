#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> ans;
set<vector<int>> s;

void dfs(int cnt, int idx) {
    if (cnt == m) {
        s.insert(ans);
        return;
    }

    for (int i = idx; i < n; i++) {
        ans.push_back(arr[i]);
        dfs(cnt+1, i + 1);
        ans.pop_back();
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    dfs(0, 0);
    
    for (const auto& v : s) {
        for (int x : v) cout << x << ' ';
        cout << '\n';
    }
    
    return 0;
}