#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#define endl "\n"

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    vector<string> tmp;
    int turn = 0;
    
    for (const string& word : words) {
        if (find(tmp.begin(), tmp.end(), word) != tmp.end()) {
            answer.push_back(turn % n + 1); // 번호
            answer.push_back(turn / n + 1); // 차례
            return answer;
        }
        
        if (tmp.size() > 0 && tmp[tmp.size() - 1].back() != word.front()) {
            answer.push_back(turn % n + 1); 
            answer.push_back(turn / n + 1); 
            return answer;
        }
        turn++;
        tmp.push_back(word);
    }
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}