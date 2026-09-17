#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int n = answers.size();
    
    vector<int> scoreA = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    vector<int> scoreB = {2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> scoreC = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    map<int, int> count;
    count.insert({0, 0});
    count.insert({1, 0});
    count.insert({2, 0});
    
    for (int i = 0; i < n; i++) {    
        if (scoreA[i % scoreA.size()] == answers[i]) count[0]++;
        if (scoreB[i % scoreB.size()] == answers[i]) count[1]++;
        if (scoreC[i % scoreC.size()] == answers[i]) count[2]++;    
    }
    
    int MAX = 0;
    int idx = 0;
    for (auto a: count) {
        if (MAX < a.second) {
            MAX = a.second;
            idx = a.first;
        }
    }
    
    for (auto a: count) {
        if (MAX == a.second) {
            answer.push_back(a.first + 1);
        }
    }
    return answer; 
}