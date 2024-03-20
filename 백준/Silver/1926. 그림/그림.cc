#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector <int>> graph(501, vector<int>(501, 0));
int visited[501][501] = {0,};
int cnt = 1; int area = 0;
vector<int> v(501, 0);
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue<pair <int, int>> q;

void bfs(int x, int y);
int n, m; 

int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j = 0;j<m;j++) {
            cin >> graph[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j = 0;j<m;j++) {
           if (graph[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
                area++;
                v.push_back(cnt); // 그림 크기
                cnt = 1; 
           }
        }
    }
    sort(v.begin(), v.end());
    cout << area << "\n";
    cout << v.back();
    return 0;
}

void bfs(int x, int y) {
    q.push({x, y});
    visited[x][y]=1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4;i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (graph[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    cnt++;
                    q.push({nx, ny});
                }
            }
        }
    }

}

