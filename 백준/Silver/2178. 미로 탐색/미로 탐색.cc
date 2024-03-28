#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[101][101] = {0,};
vector<vector<int>> graph(101, vector<int> (101,0));
int check[101][101] = {0,};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0 ,-1};
int n, m;

int bfs(int x, int y) {
    queue<pair <int, int> > q;
    q.push({x, y});
    visited[x][y] =1;
    check[x][y] = 1;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i =0;i<4;i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx >=0 && ny >=0 && nx < n && ny < m) {
                if (!visited[nx][ny] && graph[nx][ny] == 1) {
                    q.push({nx, ny});
                    check[nx][ny] = check[a][b] + 1;
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    return check[n-1][m-1];
}

int main() {
    cin >> n >> m;
    
    for (int i=0;i<n;i++) {
        string s; 
        cin >> s;
        for (int j = 0;j<m; j++) {
            graph[i][j] = s[j] -'0';
        }
    }
    cout << bfs(0,0);
    return 0;
}