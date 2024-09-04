#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    
    vector<int> coins = {500, 100, 50, 10, 5, 1};
    int value = 1000 - n;

    for (int i = 0 ; i < coins.size(); i++) {
        for (;;) {
            if (coins[i] <= value) {
                value = value - coins[i];
                ans++;
            }
            else break;
        }
    }

    cout << ans;
}