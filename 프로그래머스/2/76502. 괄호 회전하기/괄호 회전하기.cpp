#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> st;
    
    for (int i = 0; i < s.size(); i++) {
        bool check = false;
        for (int j = i; j < i + s.size(); j++) {
            int idx = j % s.size();
            if (s[idx] == '}' || s[idx] == ']' || s[idx] == ')') {
                if (st.empty()) {
                    check = false;
                    break;
                }
                else {
                    char w = st.top();
                    if ((s[idx] == '}' && w == '{') || (s[idx] == ']' && w == '[') || (s[idx] == ')' && w =='(')) {
                        check = true;
                        st.pop();
                    }
                    else {
                        check = false;
                        break;
                    }
                }
            }
            else {
                st.push(s[idx]);
            }
        }
        
        if (check == true && st.empty()) answer++;
    
        while (!st.empty()) {
            st.pop();
        }
        
    }
    
    return answer;
}