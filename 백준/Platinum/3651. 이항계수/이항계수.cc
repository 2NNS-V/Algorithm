#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long LongInteger;

// 이항계수 구하기
LongInteger bin2( LongInteger n,  LongInteger k) {
    LongInteger ret = 1;
    for ( LongInteger i = 0; i < k; ++i) {
        ret *= n - i;
        ret /= i + 1;
    }
    return ret;
}

bool compare(pair < LongInteger,  LongInteger>& a, pair < LongInteger,  LongInteger>& b) {
    if (a.first!=b.first)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
     LongInteger m; cin >> m;
    vector<pair <LongInteger, LongInteger>> v;

    for (int i=1;i<31;i++) { // k <= n-k인 k는 항상 30보다 작거나 같다.
        LongInteger low = i << 1;
        LongInteger high = m+1;

        while (low + 1 < high) {
            LongInteger mid = (low + high) >> 1;
            
            if (bin2(mid, i) <= m) low = mid;
            else high = mid;
        }

        if (bin2(low, i) == m) {
            v.push_back({low, i});
            if (i < low - i) v.push_back({low, low-i});
        }
    }

    sort(v.begin(), v.end(), compare);
    cout << v.size() << endl;
    for (const auto& pair : v) {
        cout << pair.first << " " << pair.second << endl;
    }
    // m인 이항계수의 개수 출력
    // 이항계수의 n, k 구하기
}