#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> win;
vector<int> lose;

void win_bfs(int x, vector<vector<int>>& graph) {
    queue<int> q;
    vector<int> visited(graph.size() + 1, 0);
    q.push(x);
    visited[x] = 1;
    
    while (!q.empty()) {
        int a = q.front(); 
        q.pop();
        
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i] && graph[a][i] == 1) {
                visited[i] = 1;
                q.push(i);
                win[x]++;
            }
            
        }
    }
}

void lose_bfs(int x, vector<vector<int>>& graph) {
    queue<int> q;
    vector<int> visited(graph.size() + 1, 0);
    
    q.push(x);
    visited[x] = 1;
    
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i] && graph[i][a] == 1) {
                visited[i] = 1;
                q.push(i);
                lose[x]++;
            }
            
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> graph(n + 1, vector<int> (n + 1 , 0));
    
    win.resize(n + 1, 0);
    lose.resize(n + 1, 0);
    
    for (int i = 0; i < results.size(); i++) {
        int x = results[i][0]; int y = results[i][1];
        graph[x][y] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        win_bfs(i, graph); lose_bfs(i, graph);
        
        if (win[i] + lose[i] == n-1) {
            answer++;
        }
    }
    
    return answer;
}