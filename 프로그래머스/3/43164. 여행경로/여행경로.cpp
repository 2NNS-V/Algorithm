#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> visited;
vector<string> answer;
bool found = false;

void dfs(vector<vector<string>> tickets, vector<string> path, string i, int n) {
    if (n == tickets.size()) {
        found = true;
        answer = path;
        return;
    }
    
    for (int j = 0; j < tickets.size(); j++) {
        if (tickets[j][0] == i && !visited[j]) {
            visited[j] = 1;
            path.push_back(tickets[j][1]);
            
            dfs(tickets, path, tickets[j][1], n+1);
            if (found) return;
            path.pop_back();
            visited[j] = 0;
        }
    }
            
}

vector<string> solution(vector<vector<string>> tickets) {
    visited.resize(tickets.size(), 0);
    sort(tickets.begin(), tickets.end()); 
    
    vector<string> path;
    path.push_back("ICN");
    
    dfs(tickets, path, "ICN", 0);

    return answer;
}