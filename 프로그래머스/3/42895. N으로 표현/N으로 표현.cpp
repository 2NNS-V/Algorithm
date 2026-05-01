#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<set<int>> dp(9); // N을 K개 써서 만들 수 있는 수
    
    for (int i = 1; i < 9; i++) {
    
        // N을 1개 써서 만들 수 있는 수
        int num = 0;
        for (int j = 0; j < i; j++) {
            num = num * 10 + N;
        }
    
        dp[i].insert(num);
        
        
        for (int j = 1; j < i; j++) {
            for (auto a: dp[j]) {
                for (auto b: dp[i-j]) {
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if (b != 0)
                        dp[i].insert(a/b);
                }
            }
            
        }
        
        if (dp[i].count(number))
            return i;
    }
    
    return answer;
}