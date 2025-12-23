#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> ans;

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        ans.push_back(arr[i]);
        dfs(cnt+1);
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
    dfs(0);
    return 0;
}