#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <utility>

using namespace std;

// 상좌우하
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, size = 2;
int t = 0, eat = 0;
int min_dist = INT_MAX;

queue<pair<pair<int, int>, int>> q; // x, y, distance
vector<vector<int>> arr; // 크기, 현위치
vector<vector<int>> visited; // 방문여부
vector<pair<int,int>> eaten;

// 탐색해서 위치까지 얼마나 걸리는 지 확인
// 가까운지 확인

bool bfs(int a, int b) { 
    visited.assign(n, vector<int>(n, 0));
    while (!q.empty()) q.pop();
    eaten.clear();
    min_dist = INT_MAX;
    
    q.push({{a, b}, 0});
    visited[a][b] = 1;
    
    // 최단 거리
    while (!q.empty()) {
        int x = q.front().first.first; int y = q.front().first.second;
        int dist = q.front().second;

        if (arr[x][y] > 0 && arr[x][y] < size) {
            // 먹어
            if (min_dist == INT_MAX) min_dist = dist;
            if (min_dist == dist) eaten.push_back({x, y});
        }
        q.pop();

        if (dist > min_dist) continue;  // 가까운 노드 발견 시 더이상 탐색X
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (visited[nx][ny] || arr[nx][ny] > size) continue;
                q.push({{nx, ny}, dist + 1});
                visited[nx][ny] = 1;
            }
        }
    }

    if (eaten.size() == 0) return false;
    else {
        sort(eaten.begin(), eaten.end());
        return true;
    }
}

int main() {
    cin >> n;
    arr.resize(n, vector<int> (n, 0));
    visited.resize(n, vector<int> (n, 0)); // 거리 걔산
    
    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                x = i; 
                y = j;
                arr[x][y] = 0;
            }
        }
    }
    
    while (1) {
        bool found = bfs(x, y);
        if (!found) break;
        t += min_dist;
        int sx = eaten[0].first, sy = eaten[0].second;
        arr[sx][sy] = 0;
        visited[sx][sy] = 0; 
        x = sx; y = sy;
        eat++;
        if (eat == size) {
            size++; eat = 0;
        }
    }
    cout << t;
    return 0;
}