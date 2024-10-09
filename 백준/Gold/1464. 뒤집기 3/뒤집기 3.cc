#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    string s;
    cin >> s;

    string ans = s.substr(0, 1);
    for (int i = 1 ; i < s.size(); i++) {
        if (s[i] > ans[i - 1])
            ans = s[i] + ans;
        else ans = ans + s[i];
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
}