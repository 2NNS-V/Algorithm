#include <iostream>

using namespace std;

int main() {
    long long x, y, w, s;
    cin >> x >> y >> w >> s; 

    long long a = (x + y) * w;
    long long b = min(x, y) * s;
    b += min(abs(x - y) * w, (abs(x - y) % 2 == 1 ? (abs(x - y) - 1) * s + w : abs(x - y) * s));

    cout << min(a, b);

    return 0;
}