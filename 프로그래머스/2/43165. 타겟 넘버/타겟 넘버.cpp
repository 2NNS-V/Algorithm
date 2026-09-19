#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void dfs(int i, vector<int> numbers, int target, int ans) {
    if (i == numbers.size()) {
        if (target == ans) {
            cnt++;
        }
        return;
    }
    
    dfs(i + 1, numbers, target, ans + numbers[i]);
    dfs(i + 1, numbers, target, ans - numbers[i]);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, numbers, target, 0);
    
    answer = cnt;
    
    return answer;
}