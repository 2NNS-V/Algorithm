#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> visited;
vector<vector<int>> forest;

void bfs(int i, vector<vector<int>> computers) {
    queue<int> q;
    for (int j = 0; j < computers.size(); j++) {
        if (computers[i][j]) q.push(j);
    }
    visited[i] = 1;
    
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        
        for (int j = 0; j < computers.size(); j++) {
            if (computers[n][j] == 1 && !visited[j]) {
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited.resize(computers.size());
    forest.resize(computers.size(), vector<int> (computers.size(), 0));
    
    int group = 1;
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            answer++;
            bfs(i, computers);
        }
    }
    
    return answer;
}