#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for (int i = 0;i<=s.length(); ++i) {
        
        if (i == 0) {
            if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
        }
        else {
            if (s[i-1] == ' ' && s[i] >= 'a' && s[i] <= 'z') {
                s[i]-=32;
            }
            if (s[i-1] != ' ' && s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
    
           answer += s[i-1];
        }
        
    }

    return answer;
}