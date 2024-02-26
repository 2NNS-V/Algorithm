#include <vector>
#include <queue>
using namespace std;

#define MAX 101

int visited[MAX][MAX] = {0,};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
queue<pair <int, int>> q;
int cnt[MAX][MAX] = {0,};

int bfs(int a, int b, vector<vector<int> > maps) {
    q.push({a, b});
    visited[a][b] = 1;
    cnt[a][b] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < maps.size() && ny < maps[0].size()) {
                if (visited[nx][ny] == 0 && maps[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                    cnt[nx][ny] = cnt[x][y]+1;
                }
            }
        }
    }
    if (cnt[maps.size() - 1][maps[0].size()-1] == 0) return -1;
    else return cnt[maps.size() - 1][maps[0].size()-1];
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = bfs(0,0, maps);
    return answer;
}