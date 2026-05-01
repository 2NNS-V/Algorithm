#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>

using namespace std;

vector<int> count;

void bfs(int x, vector<vector<int>>& graph) {
    queue<pair<int, int>> q;
    vector<int> visited(graph.size(), 0);
    q.push({x, 0});
    visited[x] = 1;
    
    while (!q.empty()) {
        int a = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        for (int i = 0; i < graph.size(); i++)  {
            if (!visited[i] && graph[a][i] == 1) {
                q.push({i, cnt + 1});
                count[i] = cnt + 1;
                visited[i] = 1;
            } 
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n + 1, vector<int> (n + 1, 0));
    
    for (int i = 0; i < edge.size(); i++) {
        int x = edge[i][0]; int y = edge[i][1];
        graph[x][y] = 1; graph[y][x] = 1;
    }

    count.resize(n + 1, 0);
    // 최단 경로
    bfs(1, graph);
    
    int MAX = INT_MIN;
    for (auto a: count) {
        MAX = max(a, MAX);
    }
    
    for (auto a: count) {
        if (MAX == a) answer++;
    }
    return answer;
}