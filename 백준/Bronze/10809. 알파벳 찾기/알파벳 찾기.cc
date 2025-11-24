#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    string str;
    cin >> str;

    // vector<pair<int, int> > alpha;
    map<int, int> m;
    for (int i = 97; i <= 122; i++) {
        m.insert(make_pair(i, -1));
    }
    
    // 첫 등장하는 index 저장
    for (int i = 0; i < str.size(); i++) {
        if (m[str[i] - 0] == -1) {
            m[str[i] - 0] = i;
        }

    }

    for (int i = 97; i <= 122; i++) {
        cout << m[i] << " ";
    }

}