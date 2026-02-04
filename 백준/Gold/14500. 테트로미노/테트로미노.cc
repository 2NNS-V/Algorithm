#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m; // 세로, 가로
int MAX = -INT_MAX;
vector<vector<int>> graph;
vector<vector<int>> visited;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};


void dfs(int cnt, int x, int y, int sum) {
    if (cnt == 4) {
        MAX = max(MAX, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visited[nx][ny]) {
                visited[nx][ny] = 1;
                dfs(cnt + 1, nx, ny, sum + graph[nx][ny]);
                visited[nx][ny] = 0;
            }
        }
    }
}

void checkT(int x, int y) {
    int center = graph[x][y];

    for (int i = 0; i < 4; i++) {
        int sum = center;
        bool ok = true;

        for (int j = 0; j < 3; j++) {
            int dir = (i + j) % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                ok = false;
                break;
            }
            sum += graph[nx][ny];
        }
        if (ok) MAX = max(MAX, sum);
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n, vector<int> (m, 0));
    visited.resize(n, vector<int> (m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 1;
            dfs(1, i, j, graph[i][j]);
            visited[i][j] = 0;

            checkT(i, j);
        }   

    }

    cout << MAX;
    return 0;
}