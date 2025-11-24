#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> num(9, 0);
    int cnt = 0;
    int MAX = -100000;
    for (int i = 0; i < 9; i++) {
        cin >> num[i];
        if (MAX < num[i]) {
            MAX = num[i];
            cnt = i + 1;
        }
    }

    cout << MAX << endl << cnt;

    
}