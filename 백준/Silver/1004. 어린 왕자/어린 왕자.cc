#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t; cin >> t;

    for (int j = 0 ; j<t; j++) {
        int in = 0, out = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n; cin >> n;
        int cx, cy, r;
        for (int i =0;i<n;i++) {
            cin >> cx >> cy >> r;
            if (pow(cx-x1, 2) + pow(cy - y1, 2) <= r*r) {
                if (pow(cx-x2, 2) + pow(cy-y2, 2) > r*r) out++;
            }
            if (pow(cx-x2, 2) + pow(cy - y2, 2) <= r*r) {
                if (pow(cx-x1, 2) + pow(cy-y1, 2) > r*r) in++;
            }
        }
        cout << out + in << "\n";
    }

    return 0;
    
}