#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int answer = 0;
stack<int> sub;
int cur = 1;

int solution(vector<int> order) {
    int order_size = order.size();
    
    for (auto target : order) {
        while (cur < target) {
            sub.push(cur);
            cur++;
        } 
        
        if (cur == target) {
            answer++;
            cur++;
        }
        
        else if (cur > target) {
            if (!sub.empty() && sub.top() == target) {
                sub.pop();
                answer++;
            }
            else break;
        }
    }
    
    return answer;
}