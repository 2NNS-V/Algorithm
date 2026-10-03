#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> visited;
vector<string> answer;

bool dfs(string current, vector<vector<string>>& tickets) {
    if (answer.size() == tickets.size() + 1) {
        return true;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (visited[i]) continue;
        if (tickets[i][0] != current) continue;

        visited[i] = 1;
        answer.push_back(tickets[i][1]);

        if (dfs(tickets[i][1], tickets)) {
            return true;
        }

        visited[i] = 0;
        answer.pop_back();
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    visited.resize(tickets.size(), 0);
    sort(tickets.begin(), tickets.end(),
        [](const vector<string>& a, const vector<string>& b) {
            return a[1] < b[1];
        });
    
    answer.push_back("ICN");
    dfs("ICN", tickets);
    return answer;
}