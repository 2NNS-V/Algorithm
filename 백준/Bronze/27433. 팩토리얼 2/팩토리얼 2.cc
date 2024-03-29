#include <iostream>

using namespace std;

long long int factorial(int a) {
    if (a == 1 || a == 0) return 1;
    else return a * factorial(a-1);
}

int main() {
    int n; cin >> n;
    long long int ans = factorial(n);
    cout << ans;
}