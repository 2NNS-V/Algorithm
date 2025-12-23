#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> ans;
int k;

void dfs(int cnt, int idx) {
    if (cnt == 6) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = idx; i < k; i++) {
        ans.push_back(arr[i]);
        dfs(cnt+1, i + 1);
        ans.pop_back();
    }
}

int main() {
    do {
        cin >> k;
        for (int i = 0; i < k; i++) {
            int tmp; cin >> tmp;
            arr.push_back(tmp);
        }

        dfs(0, 0);

        arr.clear();
        ans.clear();
        cout << "\n";
    } while (k != 0);
    
}