#include <iostream>
#include <algorithm>

using namespace std;

int n, ans = 0; 
int col[10001] = {0,};

int check(int level) {
    for (int i = 0; i < level; i++) {
        if (col[i] == col[level] || abs(col[i] - col[level]) == abs(i - level)) {
            return false;
        }
    }
    return true;
}

void dfs(int cnt) {
    if (cnt == n) {
        ans++;
    }
    for (int i = 0; i < n; i++) {
        col[cnt] = i;
        if (check(cnt)) dfs(cnt+1);
    }

}

int main() {
    cin >> n;
    dfs(0);
    cout << ans;
    return 0;
}