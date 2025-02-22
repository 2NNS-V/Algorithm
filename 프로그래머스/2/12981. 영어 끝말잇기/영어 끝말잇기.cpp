#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> st;
    int cnt = 0;
    
    for (auto c: words) {
        // 이미 말했던 단어인 경우
        if (find(st.begin(), st.end(), c) != st.end()) {
            answer.push_back(cnt % n + 1); // 자기 차례
            answer.push_back(cnt / n + 1); 
            return answer;
        }
        
        // 끝말잇기 규칙에 어긋나는 경우
        if (!st.empty() && st[st.size()-1].back() != c.front()) {
            answer.push_back(cnt % n + 1);
            answer.push_back(cnt / n + 1);
            return answer;
        }
        cnt++;
        st.push_back(c);
    }
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}