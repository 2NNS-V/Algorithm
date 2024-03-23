#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, k; 
int area = 0, cnt;
vector<int> ans;
int visited[101][101] = {0,};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int a, int b, vector<vector <int>> graph) {
    cnt = 1;
    queue<pair <int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (!visited[nx][ny] && !graph[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                    cnt++;
                }
            }            
        }
    }
}

int main() {
    cin >> m >> n >> k;
    vector<vector<int>> graph(n+1, vector<int>(m+1));

    for (int i =0;i<k;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i<x2;i++) {
            for (int j = y1; j<y2; j++) {
                graph[i][j] = 1;
            }
        }
    }
    
    for (int i = n -1; i>= 0; i--){
        for (int j = m -1; j>=0; j--) {
            if (!visited[i][j] && !graph[i][j]) {
                bfs(i, j, graph);
                ans.push_back(cnt);
                area++;
            }
        }
        
    }
    
    cout << area << "\n";
    sort(ans.begin(), ans.end());
    for (int i =0;i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}