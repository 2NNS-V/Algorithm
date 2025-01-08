#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0; // 이진 변환 횟수
    int zero_cnt = 0; // 0 개수
    
    while (s != "1")
    {
        cnt++; 
        int zero = 0;
        
        // 0 제거
        string tmp;
        for (char c: s) {
            if (c == '1') tmp += '1';
            else if (c == '0') zero++;
        }
        
        // tmp 길이를 2진법으로 변환
        int len = tmp.length();
        s = "";
        while (len > 0) {
            s = (len % 2 == 0 ? '0' : '1') + s;
            len /= 2;
        }
        zero_cnt += zero;
    }
    
    answer.push_back(cnt);
    answer.push_back(zero_cnt);
    return answer;
}