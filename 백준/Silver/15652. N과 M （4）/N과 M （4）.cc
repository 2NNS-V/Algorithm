#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[10001];
vector<int> ans;

void dfs(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = idx; i < n; i++) {
        ans.push_back(arr[i]);
        dfs(i, cnt + 1);
        ans.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    dfs(0, 0);
    return 0;
}
