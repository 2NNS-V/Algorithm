#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(8, 0);
    int check = 1;
    for (int i=0;i<8;++i) {
        cin >> v[i];
    }

    for (int i=0;i<7;i++) {
        if (v[i+1] - v[i] == 1) check = 0;
        else if (v[i+1] - v[i] > 1 || v[i] - v[i+1] > 1) check = 2;
    }
    if (check == 1) cout << "descending";
    else if (check == 0) cout << "ascending";
    else if (check == 2) cout << "mixed";
}
