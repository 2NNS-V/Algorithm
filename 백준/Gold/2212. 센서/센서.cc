#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main () {
    long long n, k; cin >> n >> k;
    vector<long long> sensors(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> sensors[i];
    }

    // * 최대 K개의 집중국의 수신 가능한 영역의 길이의 합을 최소화
    sort(sensors.begin(), sensors.end());
    vector<long long>diff;
    for (long long i = 1; i < sensors.size(); i++) {
        diff.push_back(sensors[i]-sensors[i-1]);
    }
    sort(diff.begin(), diff.end(), greater<int>()); 

    int ans = 0;
    for (long long i = k - 1; i < diff.size(); i++) {
        ans += diff[i];
    }
    cout << ans;
}