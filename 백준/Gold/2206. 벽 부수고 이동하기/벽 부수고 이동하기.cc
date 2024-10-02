#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<vector<int> > > graph; // * z축에는 벽을 부수기 전과 후 거리 저장
queue<pair <int, pair <int, int> > > q;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int bfs() { 
    while (!q.empty()) {
        int broken = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;

        q.pop();

        if (x == n-1 && y == m-1) return graph[n-1][m-1][broken] + 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0  && nx < n && ny >= 0 && ny < m) {
                if (graph[nx][ny][0] == 1) { // * 벽인 경우
                    if (broken == 0) { // * 벽을 부수지 않았을 때
                        graph[nx][ny][1] = graph[x][y][0] + 1;
                        q.push(pair<int, pair<int, int> > (1, pair<int, int> (nx, ny)));
                    }
                }
                else if (graph[nx][ny][0] == 0) { // * 벽이 아닌 경우
                    if (broken == 0 || graph[nx][ny][broken] == 0) { // * 벽을 부수지 않았거나 graph를 방문한 적 없다면
                        graph[nx][ny][broken] = graph[x][y][broken] + 1;
                        q.push(pair <int, pair<int, int> >(broken, pair<int, int> (nx, ny)));
                    }
                }
            }
        }
    }

    return -1;
    
}

int main() {
    cin >> n >> m;
    graph.resize(n, vector<vector<int> > (m, vector<int> (2)));

    // * 0: 이동 가능, 1: 벽
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            graph[i][j][0] = tmp - '0';
        }
    }

    q.push(pair<int, pair<int, int> > (0, pair<int, int> (0, 0)));
    int ans = bfs();
    cout << ans;

    return 0;

}