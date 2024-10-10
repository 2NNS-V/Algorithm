#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    int A = stoi(a), B = stoi(b), C = stoi(c);

    cout << A + B - C << endl;
    cout << stoi(a + b) - C << endl;

    return 0;
}   