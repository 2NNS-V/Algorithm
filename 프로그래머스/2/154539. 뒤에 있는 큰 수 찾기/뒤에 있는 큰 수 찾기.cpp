#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iostream>

using namespace std;

// 해당 원소보다 클 때, 거리 값
stack<pair<int, int> > st;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    
    for (int i = 0; i < numbers.size(); i++) {
        if (st.empty() || numbers[i] <= st.top().first) {
            st.push({numbers[i], i});
        }
        else {
            while (!st.empty() && numbers[i] > st.top().first) {
                int idx = st.top().second;
                answer[idx] = numbers[i];
                st.pop();
            }
            
            st.push({numbers[i], i});
        }
        
        
    }
    
    while (!st.empty()) {
        int idx = st.top().second;
        answer[idx] = -1;
        st.pop();
    }
    return answer;
}