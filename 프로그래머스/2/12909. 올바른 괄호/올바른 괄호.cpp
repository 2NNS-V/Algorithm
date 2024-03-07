#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = false; // 답
    char tmp;
    bool flag = false; // 짝이 맞는지 확인
    vector<char> v;
    
    if (s[0] == '(' && s[s.length()-1] == ')') {
        for (int i=0;i<s.length();++i) {
            if (s[i] == '(') v.push_back(s[i]);
            else {
                if (v.empty()) { // 스택이 빈 경우
                    flag = true;
                    break;
                }
                else v.pop_back();
            }
        }
    }
    
    else {
        flag = true;
        answer = false;
    }
    
    if (!flag){
        if (v.empty()) answer = true;
    }
    
    return answer;
}