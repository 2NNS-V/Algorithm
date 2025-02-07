#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zero_cnt = 0;
    
    while (s != "1") {
        cnt++;
        int zero = 0;
        string tmp;
        for (auto c: s) {
            if (c == '0') zero++;
            else tmp += '1';
        }
        
        int len = tmp.length();
        s = "";
        while (len) {
            s = (len % 2 == 0 ? '0' : '1') + s;
            len /= 2;
        }
        zero_cnt += zero;
    }
    
    answer.push_back(cnt);
    answer.push_back(zero_cnt);
    return answer;
}