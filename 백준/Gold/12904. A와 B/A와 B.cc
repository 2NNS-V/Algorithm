#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    while (1) {
        if (t[t.length()-1] == 'A') {
            t.pop_back();
        }
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }

        if (s.length() == t.length()) {
            if (t == s) cout << 1;
            else cout << 0;
            break;
        }
    }

}