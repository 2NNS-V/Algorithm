#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    string ans;
    if (str == "SONGDO") {
        ans = "HIGHSCHOOL";
    }
    else if (str == "CODE") {
        ans = "MASTER";
    }
    else if (str == "2023") {
        ans = "0611";
    }
    else if (str == "ALGORITHM") {
        ans = "CONTEST";
    }
    cout << ans;
    return 0;
}