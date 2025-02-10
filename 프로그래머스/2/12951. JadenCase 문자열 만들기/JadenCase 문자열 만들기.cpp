#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool newWord = true;
    
    for (auto c: s) {
        if (c == ' ') {
            answer += c;
            newWord = true;
        }
        else {
            if (newWord && isalpha(c)) answer += toupper(c);
            else answer += tolower(c);
            newWord = false;
            
        }
    }
    
    

    return answer;
}