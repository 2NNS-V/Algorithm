#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<char> > graph;
queue<pair<int, int> > q;
queue<pair<int, int> > fire;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;
int t, w, h;

void moveFire() {
    int fire_size = fire.size();
    for (int i = 0; i < fire_size; i++) {
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && (graph[nx][ny] == '.' || graph[nx][ny] == '@')) {
                graph[nx][ny] = '*';
                fire.push(pair<int, int> (nx, ny));
            }
        }
    }
}

int bfs() {
    int ans = 0;
    while (!q.empty()) {
        ans++;
        moveFire();

        int size = q.size();
        for (int j = 0; j < size; j++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < h && ny >= 0 && ny < w && graph[nx][ny] == '.') {
                    graph[nx][ny] = '@';
                    q.push(pair<int, int> (nx, ny));
                }
                else if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                    return ans;
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> w >> h;
        graph.resize(h, vector<char>(w));

        // * '.': 빈 공간, '#': 벽, '@': 상근이의 시작 위치, '*': 불
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> graph[i][j];
                if (graph[i][j] == '@') {
                    q.push(pair<int, int> (i,j));
                }
                else if (graph[i][j] == '*') {
                    fire.push(pair<int, int> (i,j));
                }
            }
        }

        int ans = bfs();
        if (ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;

        while (!q.empty()) q.pop(); 
        while (!fire.empty()) fire.pop();
        graph.clear(); 
    }
    return 0;
}