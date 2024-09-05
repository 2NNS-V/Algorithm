#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;
    
    vector<int> scores(n, 0);
    for (int i = 0; i<n; i++) {
        cin >> scores[i];
    }
    sort(scores.begin(), scores.end());

    long long ans = 0;
    for (int i = 0; i < scores.size(); i++) {
        ans += abs(scores[i] - (i + 1));
    }
    cout << ans;
}