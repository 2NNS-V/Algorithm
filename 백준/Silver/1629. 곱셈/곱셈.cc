#include <iostream>

using namespace std;

long long a, b, c, half;

long long divide_and_conquer(long long b) {
    if (b == 0) return 1;
    if (b == 1) return a % c;

    long long half = divide_and_conquer(b / 2) % c;
    if (b % 2 == 0) {
        return half * half % c;
    } else {
        return half * half % c * a % c;
    }    
}

int main() {
    cin >> a >> b >> c;
    cout << divide_and_conquer(b) << endl;
    return 0;
}