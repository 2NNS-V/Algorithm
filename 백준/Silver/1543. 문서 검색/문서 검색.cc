#include <iostream>
#include <string>

using namespace std;

int main() {    
    string str, find;
    getline(cin, str);
    getline(cin, find);

    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        bool match = true; 
        for (int j = 0; j < find.length(); j++) {
            if (str[i + j] != find[j]) {
                match = false;
                break;
            } 
        }
        if (match) {
            cnt++;
            i += find.length() - 1;
        } 
    }

    cout << cnt;
}