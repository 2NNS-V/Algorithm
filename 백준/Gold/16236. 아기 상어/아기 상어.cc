#include <iostream>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

int n, t = 0;
int shark_size = 2;

int map[21][21] = {0,}; 
int visited[21][21] = {0,};

// 위, 좌, 우, 아래
int dx[4] = {0, -1, 1, 0}; 
int dy[4] = {-1, 0, 0, 1};

struct Target {
    int r, c, d;
    bool found;
};

queue<pair<int, int> > q;
queue<int> dist_tmp;

int dist[21][21] = {0,};

Target bfs(int sx, int sy) {
    int best = INT_MAX;

    while (!q.empty()) q.pop();
    while (!dist_tmp.empty()) dist_tmp.pop();
    vector<pair<int, int> > eat;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    q.push(make_pair(sx, sy));
    dist_tmp.push(0);
    visited[sx][sy] = 1;


    // 최단 거리 구하기
    while (!q.empty()) {
        int x = q.front().first; int y = q.front().second;
        int d = dist_tmp.front();
        dist[x][y] = d;
        q.pop(); dist_tmp.pop();

        // 먹을 수 있는지 확인 (현재 상어 크기보다 작아야 함)
        if (map[x][y] != 0 && map[x][y] < shark_size) { 
            if (best == INT_MAX) best = d;
            if (d == best) eat.push_back(make_pair(x, y));
        }   

        if (d > best) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
            if (map[nx][ny] > shark_size) continue; // 지나갈 수 없음
            
            q.push(make_pair(nx, ny)); 
            dist_tmp.push(d+1); // 이동 가능
            visited[nx][ny] = 1;
        }
    }

    // 먹을 수 있는 물고기
    if (eat.empty()) return {-1, -1, -1, false};
    sort(eat.begin(), eat.end());
    return {eat[0].first, eat[0].second, best, true};
}

int main() {
    cin >> n;
    
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                sx = i; sy = j;
            }
        }
    }

    map[sx][sy] = 0;
    int eaten = 0;

    while (1) {
        Target tg = bfs(sx, sy);
        if (!tg.found) break;
        t += tg.d;
        sx = tg.r; sy = tg.c;
        map[sx][sy] = 0;
        eaten++;
        if (eaten == shark_size) {
            shark_size++;
            eaten = 0;
        }
    }
    cout << t;
    return 0;
}