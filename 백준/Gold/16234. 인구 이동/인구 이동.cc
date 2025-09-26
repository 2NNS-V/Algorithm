#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

int days = 0;
int n, l, r;
int map[51][51] = {0,};
int visited[51][51] = {0,};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int currX, int currY) {
    queue<pair<int, int> > q; // 위치
    vector<pair<int, int> > uni; // 연합국 정보
    int sum = map[currX][currY]; // 연합국 전체 인구
    visited[currX][currY] = 1;

    q.push(make_pair(currX, currY));
    uni.push_back(make_pair(currX, currY));

    while (!q.empty()) {
        int x = q.front().first; int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            // if (!uni.empty() && find(uni.begin(), uni.end(), make_pair(nx, ny)) != uni.end()) continue;
            if (visited[nx][ny]) continue;

            if (abs(map[nx][ny] - map[x][y]) >= l && abs(map[nx][ny] - map[x][y]) <= r) {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                uni.push_back(make_pair(nx,ny));
                sum += map[nx][ny]; // 연합국 전체 덧셈
            }
            
        }
    }

    if (uni.size() == 1) return false;

    // 인구 이동
    int value = sum / (int)uni.size();
    for (int i = 0; i < (int)uni.size(); i++) {
        int x = uni[i].first; int y = uni[i].second;
        map[x][y] = value;
    }

    return true;

}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    while (1) {
        bool stop = true;
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (bfs(i, j)) stop = false; 
                }
            }
        }

        if (stop) break;
        days++;
    }

    cout << days;

}