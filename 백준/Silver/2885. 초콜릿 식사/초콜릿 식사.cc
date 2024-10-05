#include <iostream>

using namespace std;

int main() {
    long long k;
    cin >> k;

    long long num = 1;
    while (k > num) {
        num *= 2;
    }

    cout << num << " ";

    long long cnt = 0;
    while (k % num != 0) {
        cnt++;
        num /= 2;
    } 

    cout << cnt;

}