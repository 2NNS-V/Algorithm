#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dict;

    for (int i = 0; i < 26; i++) {
        dict.push_back(string(1, s[i]));
    }

    string prev;
    int i = 0;
    while (i < msg.size()) {
        prev += msg[i]; 
        
        auto it1 = find(dict.begin(), dict.end(), prev);
        if (it1 != dict.end()) { // dict에 존재하는 경우
            // msg[i]를 추가해서 존재하지 않을 때까지 반복 
            // -> 존재하지 않는 경우에 전 str의 idx를 추가
            int j = i + 1;
            string curr = prev;
            while (1) {
                curr += msg[j++];
                auto it2 = find(dict.begin(), dict.end(), curr);
                if (it2 == dict.end())  { // dict에 존재하지 않는 경우
                    dict.push_back(curr);
                    break;
                }
                i++;
                prev = curr;
            }
            
            auto it3 = find(dict.begin(), dict.end(), prev);
            int idx = it3 - dict.begin() + 1;
            answer.push_back(idx);
        } 
        i++;
        prev.clear();
    }
    
    return answer;
}