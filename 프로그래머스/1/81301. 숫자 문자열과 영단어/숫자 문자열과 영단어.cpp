#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string tmp;
    
    for (int i = 0; i < s.size(); ) {
        if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
            tmp.push_back(s[i]);
            i++;
        }
        else if (s[i] == 's') {
            if (s[i+1] == 'i') {
                tmp.push_back('6');
                i += 3;
            }
            else if (s[i+1] == 'e') {
                tmp.push_back('7');
                i += 5;
            }
        }
        else if (s[i] == 'o') {
            tmp.push_back('1');
            i += 3;
        }
        else if (s[i] == 'z') {
            tmp.push_back('0');
            i+= 4;
        }
        else if (s[i] == 'e') { 
            tmp.push_back('8');
            i += 5;
        }
        else if (s[i] == 'n') {
            tmp.push_back('9');
            i += 4;
        }
        else if (s[i] == 't'){
            if (s[i+1] == 'w') {
                tmp.push_back('2');
                i += 3;
            }
            else if (s[i+1] == 'h') {
                tmp.push_back('3');
                i += 5;
            }
        }
        else if (s[i] == 'f') {
            if (s[i+1] == 'o'){
                tmp.push_back('4');
                i+= 4;
            }
            else if (s[i+1] == 'i') {
                tmp.push_back('5');
                i += 4;
            }
        }
    }
    
    for (int i = 0; i < tmp.size(); i++) {
        answer += (tmp[i] - '0') * pow(10, (tmp.size() - i - 1));
    }
    
    return answer;
}