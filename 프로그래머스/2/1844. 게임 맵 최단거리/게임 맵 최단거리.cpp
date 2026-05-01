#include<vector>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y, vector<vector<int>>& maps, vector<vector<int>>& visited, int n, int m) {
    queue<pair<int, int>> q;
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    
    q.push({x, y});
    visited[x][y] = 1;
    cnt[x][y] = 1;
    
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int na = dx[i] + a;
            int nb = dy[i] + b;
             
            if (na >= 0 && na < n && nb >= 0 && nb < m) {
                if (!visited[na][nb] && maps[na][nb] == 1) {
                    q.push({na, nb});
                    visited[na][nb] = 1;
                    cnt[na][nb] = cnt[a][b] + 1;
                }
            }
        }
    }
    
    if (cnt[n-1][m-1] == 0) return -1;
    else return cnt[n-1][m-1];
}

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> visited(n, vector<int> (m, 0));
    
    return bfs(0, 0, maps, visited, n, m);
}