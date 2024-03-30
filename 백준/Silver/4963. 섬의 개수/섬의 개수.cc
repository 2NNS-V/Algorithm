#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int graph[51][51];
int visited[51][51] = {0,};
int w, h, cnt = 0;


int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

void bfs(int i, int j) {
    queue<pair <int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0;i<8;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if (!visited[ny][nx] && graph[ny][nx]) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
    }
}

int main() {
    while (1) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        
        for (int i=0;i<h;i++) {
            for (int j = 0;j<w;j++) {
                cin >> graph[i][j];
            }
        }

        for (int i=0;i<h;i++) {
            for (int j = 0;j<w;j++) {
                if (!visited[i][j] && graph[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        cnt = 0;
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}