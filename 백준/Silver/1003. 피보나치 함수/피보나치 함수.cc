#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> one; vector<int> zero;

void fib(int n) {
    for (int i=2;i<41;i++) {
        zero.push_back(zero[i-1] + zero[i-2]);
        one.push_back(one[i-1] + one[i-2]);
    }
}

int main() {
   int t; cin >> t;
   one.push_back(0); one.push_back(1);
   zero.push_back(1); zero.push_back(0);

   for (int i=0;i<t;i++) {
        int n; cin >> n;
        fib(n);
        cout << zero[n] << " " << one[n] << "\n";
   }    
}