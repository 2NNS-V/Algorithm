#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<char> > graph;
vector<vector<int> > visited;

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int a, int b) {
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    visited[a][b] = 1;

    while (!q.empty()) {
        int x = q.front().first; int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (visited[nx][ny] == 0 && graph[nx][ny] == '1') {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = visited[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n, vector<char> (m, 0));
    visited.resize(n, vector<int> (m, 0));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;

        for (int j = 0; j < line.size(); j++) {
            graph[i][j] = line[j];
        }
    }

    bfs(0, 0);
    cout << visited[n-1][m-1];
    
}