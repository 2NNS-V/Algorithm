#include <iostream>
#include <vector>

using namespace std;

vector<long long int> arr(1000001);

int main() {
    int n; cin >> n;
    int sum = 0;
    for (int i =0;i<n;i++) {
        cin >> arr[i];
    }
    int b, c; cin >> b >> c;
    long long int ans = n; // 총감독관

    for (int i=0;i<n;i++) {
        arr[i] -= b;
        if (arr[i] <= 0) continue;
        ans += arr[i] / c;
        if (arr[i] % c) ans++;
    }
    cout << ans;
}
 