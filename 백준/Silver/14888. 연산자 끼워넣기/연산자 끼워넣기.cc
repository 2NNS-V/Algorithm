#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> arr(101,0); int n;
int op[4]; int min_value = INT_MAX, max_value = INT_MIN; 

int calc(int pos, int i, int v) {
    if (pos == 0) return v+arr[i];
    else if (pos == 1) return v-arr[i];
    else if (pos == 2) return v * arr[i];
    return v/arr[i];
}

void func(int cnt, int sum) {
    if (cnt == n) {
        min_value = min(min_value, sum);
        max_value = max(max_value, sum);
        return;
    }

    for (int i=0;i<4;i++) {
        if (op[i] > 0) {
            op[i]--;
            func(cnt+1, calc(i, cnt, sum));
            op[i]++;
        }
    }
}

int main() {
    cin >> n;

    for (int i=0;i<n;i++) cin >> arr[i];
    for (int i=0;i<4;i++) cin >> op[i];

    func(1, arr[0]);
    cout << max_value << "\n" << min_value;
}