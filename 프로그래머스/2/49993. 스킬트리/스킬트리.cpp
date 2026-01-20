#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (auto tree: skill_trees) {
        vector<int> idx;
        
        for (int i = 0; i < skill.length(); i++) {
            auto it = tree.find(skill[i]);
            if (it == string::npos) idx.push_back(27);
            else idx.push_back(it);
        }
        
        bool check = true;
        auto prev = idx[0]; // 전 index
        int i = 0;
        for (i = 0; i < idx.size(); i++) {
            cout << idx[i] << " ";
            if (prev > idx[i]) {
                check = false;
                break;
            }
            prev = idx[i];
        }
        if (check) answer++;
        cout << answer << endl;
        
    }

    return answer;
}