#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int solution(string s) {
    int answer = INT_MAX;
    int n = (int)s.size();
    
    for (int k = 1; k <= n; k++) {
        string ans;
        string prev = s.substr(0, k);
        int cnt = 1;
        
        for (int i = k; i < n; i += k) {
            string str = s.substr(i, k);
            
            if (str == prev) cnt++;
            else {
                if (cnt > 1) ans += to_string(cnt);
                ans += prev;
                prev = str;
                cnt = 1;
            }
        }
        
        if (cnt > 1) ans += to_string(cnt);
        ans += prev;
        
        if (answer > ans.size()) answer = ans.size();
    }
        
    return answer;
}