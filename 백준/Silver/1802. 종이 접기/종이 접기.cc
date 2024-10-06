#include <iostream>

using namespace std;


bool paper(string str, int start, int end) {
    if (start >= end) return true;

    int left = start; int right = end;
    while (left < right) {
        if (str[left] == str[right]) return false;
        left++; right--;
    }
    return paper(str, start, right-1);
}   

int main() {
    int t;
    cin >> t;

    while (t--) {
        // * 1: out, 0: in
        string str;
        cin >> str;

        if (str.length() == 1) {
            cout << "YES" << endl;
            continue;
        }

        if (paper(str, 0, str.length()-1)) { // * true
            cout << "YES" << endl;
        }
        else { // * false
            cout << "NO" << endl;
        }
    }
}