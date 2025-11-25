#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > graph;
vector<vector<int> > visited;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y) {
    visited[x][y] = 1;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visited[nx][ny] && graph[nx][ny] == 1) {
                dfs(nx, ny);
            }
        }
    }
    
}

int main() {
    int t; cin >> t; 

    for (int i = 0; i < t; i++) {
        int k; cin >> m >> n >> k;

        int ans = 0;
        graph.assign(n, vector<int> (m, 0));
        visited.assign(n, vector<int> (m, 0));

        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            graph[y][x] = 1; // 배추 위치
        }
        

        for (int j = 0; j < n; j++) {
            for (int p = 0; p < m; p++) {
                if (graph[j][p] == 1 && !visited[j][p]) {
                    dfs(j, p);
                    ans++;
                }
            }
        }
        
        cout << ans << endl;
    }
}