#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target, int cnt, int sum);

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = dfs(numbers, target, 0,0);
    return answer;
}

int dfs(vector<int> numbers, int target, int cnt, int sum) {
    if (cnt == numbers.size()) {
        if (sum == target) return 1;
        else return 0;
    }
    
    return dfs(numbers, target, cnt+1, sum + numbers[cnt]) + dfs(numbers, target, cnt+1, sum - numbers[cnt]);
}