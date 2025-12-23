#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> ans;
int arr[10001] = { 0, };
int visited[10001] = { 0 ,};

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        ans.push_back(arr[i]);
        dfs(cnt + 1);
        visited[i] = 0;
        ans.pop_back();

    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        arr[i - 1] = i;
    }
    dfs(0);

    return 0;
}
