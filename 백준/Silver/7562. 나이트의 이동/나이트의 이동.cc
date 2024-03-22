#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int visited[300][300] = {0,};
int cnt[300][300] = {0,};
queue<pair <int, int>> q;
int src_x, src_y, dest_x, dest_y, l; 

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

void bfs(int x, int y) {
    q.push({x, y});
    visited[x][y] = 1;
    
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (a == dest_x && b == dest_y) {
            cout << cnt[a][b] << "\n";
            while (!q.empty()) q.pop();
            break;
        }

        for (int i = 0; i < 8;i++) {
                int nx = dx[i] + a;
                int ny = dy[i] + b;

            if (nx < l && ny < l && nx >= 0 && ny >= 0) {
                if (!visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                    cnt[nx][ny] = cnt[a][b] + 1;
                }
            }
        }
    }
}

int main() {
    int n; cin >> n;

    for (int i=0;i<n;i++) {
        cin >> l;
        cin >> src_x >> src_y; 
        cin >> dest_x >> dest_y;

        bfs(src_x, src_y);
        memset(visited, 0, sizeof(visited));
        memset(cnt, 0, sizeof(cnt));
    }
}