#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> m;

// order.size() 중에서 r개 뽑아서 만들 수 있는 조합 구하기
void getComb(string order, int r) {
    sort(order.begin(), order.end());
    
    vector<int> sub(order.length(), 1);
    for (int i = 0; i < r; i++) {
        sub[i] = 0;
    }
    sort(sub.begin(), sub.end());

    do {
        string s1 = "";
        for(int i = 0; i < sub.size(); i++) {
            if (!sub[i]) {
                s1 += order[i];
            }
        }
        m[s1]++;
    } while (next_permutation(sub.begin(), sub.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int j = 0; j < course.size(); j++) {
        int r = course[j];
        for (auto order: orders) {
            if (r <= order.size())
                getComb(order, r);
        }

        int maxCnt = 0;
        for (auto i: m) {
            if (i.second >= 2) maxCnt = max(maxCnt, i.second);
        }
        for (auto i: m) {
            if (i.second == maxCnt && maxCnt >= 2) answer.push_back(i.first);
        }
        m.clear();
    }
    sort(answer.begin(), answer.end());
    return answer;
}