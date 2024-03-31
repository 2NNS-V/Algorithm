#include <iostream>

using namespace std;

int cnt = 1, i = 1;

int main() {
    int n; cin >> n;
    while (n > i) {
        i += 6*cnt;
        cnt++;
    }
    cout << cnt;
}