#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int cal(int n, int p) { // 각 자리 수로 분리  
    int ans = 0;
    while (n) {
        int last = n % 10;
        ans += pow(last,p);
        n /= 10;
    }
    return ans;
}

int main() {
    int a, p; cin >> a >> p;

    vector<int> d;
    d.push_back(a); 
    bool ans = true;

    while (1) {
        int value = cal(d.back(), p); 
        
        auto i = find(d.begin(), d.end(), value);
        if (i != d.end()) {
            d.erase(i, d.end());
            break;
        }
        d.push_back(value);
    }


    cout << d.size();
}