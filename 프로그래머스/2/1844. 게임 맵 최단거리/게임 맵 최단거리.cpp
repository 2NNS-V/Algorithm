#include <vector>
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int visited[101][101] = {0,};
int MIN = INT_MAX;

void bfs(int a, int b, int n, int m, vector<vector<int>> maps) {
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();        
        
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (!visited[nx][ny] && maps[nx][ny]) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    bfs(0, 0, n, m, maps);
    if (visited[n-1][m-1] == 0) return -1;
    else return visited[n-1][m-1];
}