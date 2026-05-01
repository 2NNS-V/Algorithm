#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string s; cin >> s;
    int k, m; cin >> k >> m;

    string tmp;
    
    unordered_map<long long, int> mp;
    int n = s.size();


    if (k > n) {
        cout << "0" << endl;
        return 0;
    }


    long long cur = 0;
    long long mask = (1LL << k) - 1;

    // 첫 K개 초기 hash
    for (int i = 0; i < k; i++) {
        cur = (cur << 1) + (s[i] - '0'); // 숫자로 만들어주기
    }

    mp[cur]++;
    if (mp[cur] >= m) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = k; i < n; i++) {
        cur = ((cur << 1) & mask) + (s[i] - '0');

        mp[cur]++;

        if (mp[cur] >= m) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << "0" << endl;
    return 0;
}