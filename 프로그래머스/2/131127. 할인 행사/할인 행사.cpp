#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    
    for (int i = 0; i < want.size(); i++) {
        m[want[i]] = number[i];
    }
    
    
    for (int i = 0; i <= discount.size() - 10; i++) {
        map<string, int> tmp;
        for (int j = i; j < i + 10; j++) {
            tmp[discount[j]]++;
        }
        
        // m에 존재하지 않거나 수량이 다르다면 X
        bool matches = true;
        for (auto item : m) {
            if (tmp[item.first] != item.second || tmp.find(item.first) == tmp.end()) {
                matches = false;
                break;
            }
        }

        if (!matches) continue;
        answer++;
        
    }
    return answer;
}