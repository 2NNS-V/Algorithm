#include <iostream>


int main() {
    using namespace std;

    int n;
    cin >> n;
    
    int cnt = 0;

    while (n >= 0) {
        if (n % 5 == 0) {
            cnt += n / 5;
            cout << cnt;
            break;
        } 
        n -= 2;
        cnt++;
    }
    if (n < 0) {
        cout << -1;
        return 0;
    }
    return 0;
}