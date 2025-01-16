#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    queue<char> q;

    for (auto c : s) {
        q.push(c);
    }

    for (int i = 0; i < s.size(); i++) {
        stack<char> stack; // 스택 초기화
        bool isValid = true;

        for (int j = 0; j < s.size(); j++) {
            char ss = q.front();
            q.pop();

            if (ss == '{' || ss == '(' || ss == '[') {
                stack.push(ss);
            } else if (ss == '}' || ss == ')' || ss == ']') {
                if (!stack.empty()) {
                    char tmp = stack.top();
                    if ((ss == '}' && tmp == '{') || 
                        (ss == ']' && tmp == '[') || 
                        (ss == ')' && tmp == '(')) {
                        stack.pop();
                    } else {
                        isValid = false; // 올바르지 않은 경우
                    }
                } else {
                    isValid = false; // 올바르지 않은 경우
                }
            }

            q.push(ss); // 회전 복원
        }

        if (isValid && stack.empty()) {
            answer++;
        }

        // 왼쪽으로 한 칸 회전
        char front = q.front();
        q.pop();
        q.push(front);
    }

    return answer;
}
