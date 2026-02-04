#include <iostream>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

int n, m;
int map[10][10] = {0,};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int ans = -1;


void bfs() {
    queue<pair<int, int> > q;

    int temp[10][10] = {0,};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || temp[nx][ny] != 0) continue;
            q.push(make_pair(nx, ny));
            temp[nx][ny] = 2;
        }

    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) cnt++;
        }
    }

    if (cnt > ans) ans = cnt;

}

void search(int num) {
    if (num == 3) {
        bfs();
        return;
    }
    
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;
                    search(num + 1);
                    map[i][j] = 0;
                }
                
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    search(0);
    
    cout << ans;
    return 0;

}