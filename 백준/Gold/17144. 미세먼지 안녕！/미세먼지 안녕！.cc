#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };


vector<vector<int>> g;
vector<vector<int>> tmp;
queue<pair<int, int>> q;
int r, c, t;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int cnt = 0;
        int spread = g[x][y] / 5;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (g[nx][ny] != -1) {
                    cnt++;
                    tmp[nx][ny] += spread;
                }
            }
        }
        tmp[x][y] += g[x][y] - spread * cnt;
    }
}

int main() {
    cin >> r >> c >> t;

    g.resize(r, vector<int>(c, 0));
    tmp.resize(r, vector<int>(c, 0));
    
    queue<int> air;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> g[i][j];
            if (g[i][j] == -1) {
                air.push(i);
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][j] = g[i][j];
        }
    }

    int x1 = air.front(); 
    air.pop();
    int x2 = air.front(); 
    air.pop();

    // t초 동안 미세먼지 확산 + 공기청정기 작동
    while (t--) {
        tmp.assign(r, vector<int>(c, 0));
        tmp[x1][0] = -1; tmp[x2][0] = -1; 

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] != 0 && g[i][j] != -1)
                    q.push(make_pair(i, j));    
            }
        }
        
        
        bfs();
        g = tmp;
        
        // 공기청정기 작동(회전)
        for (int i = x1-1; i > 0; i--) g[i][0] = g[i-1][0];
        for (int j = 0; j < c-1; j++) g[0][j] = g[0][j+1];
        for (int i = 0; i < x1; i++) g[i][c-1] = g[i+1][c-1];
        for (int j = c-1; j > 1; j--) g[x1][j] = g[x1][j-1];
        g[x1][1] = 0;

        for (int i = x2+1; i < r-1; i++) g[i][0] = g[i+1][0];
        for (int j = 0; j < c-1; j++) g[r-1][j] = g[r-1][j+1];
        for (int i = r-1; i > x2; i--) g[i][c-1] = g[i-1][c-1];
        for (int j = c-1; j > 1; j--) g[x2][j] = g[x2][j-1];
        g[x2][1] = 0;

    }

    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (g[i][j] == -1) g[i][j] = 0;
            sum += g[i][j];
        }   
    }

    cout << sum;
}