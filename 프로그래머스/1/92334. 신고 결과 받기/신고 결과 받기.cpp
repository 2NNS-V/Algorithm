#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>

using namespace std;

// 이용자 id = id_list
// 신고한 이용자의 id = report
// 정지 기준 = k
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    unordered_map<string, int> users; // 신고한 횟수 저장
    unordered_map<string, set<string>> reported_users; // 신고한 사람 -> 신고 당한 사람
    
    for (int i = 0; i < id_list.size(); i++) {
        users[id_list[i]] = 0;
        cout << id_list[i] << "\n";
    }
    
    cout << endl;

    for (const string& str : report) {
        string reporter, reported;
        stringstream ss(str);
        ss >> reporter >> reported;
        
        reported_users[reported].insert(reporter); 
    }
        
        for (auto iter : reported_users) {
            if (iter.second.size() >= k) { // k보다 큰 경우
                for (auto in : iter.second) {
                    users[in]++;
                }
            }
        }
        
    
    for (int i = 0; i < id_list.size(); i++) {
        cout << users[id_list[i]];
        answer.push_back(users[id_list[i]]);
    }
    
    // 메일 받은 횟수
    return answer;
}