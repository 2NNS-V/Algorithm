#include <iostream>
#include <algorithm>

using namespace std;

int n, ans = -1;
string to;

char change(char ch){
    if (ch == '0') return '1';
    else return '0';
}
void solve(int cnt, string& from, int i) {
    if (i == n) {
        if (from[i - 1] == to[i - 1]) {
            ans = ans == -1 ? cnt : min(ans, cnt);
        }
        return;
    }

    if (from[i-1] == to[i-1]) {
        solve(cnt, from, i + 1);    
    }
    else {
        from[i-1] = change(from[i-1]);
        from[i] = change(from[i]);
        if (i + 1 < n) from[i+1] = change(from[i+1]);
        solve(cnt + 1, from, i + 1);
    }
}
int main() {
    cin >> n;
    
    string from;
    cin >> from >> to;

    string tmp = from;
    solve(0, from, 1);

    if (ans == -1){
        from = tmp;
        from[0] = change(from[0]);
        from[1] = change(from[1]);
        solve(1, from, 1);
    }

    cout << ans;
}