#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stack;
    for (auto c: s) {
        if (c == '(') stack.push(c);
        else {
            if (stack.empty()) return false;
            char ch = stack.top();
            if (ch == '(') stack.pop();
        }
    }
    
    if (stack.empty()) answer = true;
    else answer = false;
    
    return answer;
}