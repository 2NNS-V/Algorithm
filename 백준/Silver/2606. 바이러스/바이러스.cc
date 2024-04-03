#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
int visited[101] = {0,};
int cnt = 0;

void dfs(int x) {
    visited[x] = 1;
    
    for (int i =0;i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) {
            dfs(y); cnt++;
        }
    }
}

int main() {
    int computer; cin >> computer;
    int network; cin >> network;
    for (int i = 0; i<network;i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    dfs(1);
    cout << cnt; 
}