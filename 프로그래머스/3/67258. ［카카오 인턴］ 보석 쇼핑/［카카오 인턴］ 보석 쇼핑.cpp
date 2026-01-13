#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <climits>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_set<string> s(gems.begin(), gems.end());
    unordered_map<string, int> cnt;
    
    if (s.size() == 1) {
        return {1, 1};
    }

    int start = 0;
    int have = 0, ans = INT_MAX;
    int ans_s = 0, ans_e = 0;
    
    for (int end = 0; end < gems.size(); end++) {
        if (++cnt[gems[end]] == 1) have++;
        
        while (have == s.size()) {
            int len = end - start + 1;
            if (len < ans) {
                ans = len;
                ans_s = start;
                ans_e = end;
            }
            
            if (--cnt[gems[start]] == 0) have--;
            start++;
        }
        
    }
    
    return {ans_s + 1, ans_e + 1};
}