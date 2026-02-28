#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

int n, eat = 0;
int t = 0, cnt = 0;
int shark_size = 2;
int min_dist = INT_MAX;
vector<vector<int>> arr;
vector<pair<int,int>> eaten;
vector<vector<int>> visited;

// 상좌하우
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int a, int b) {
    queue<pair<pair<int, int>, int>> q;
    eaten.clear();
    visited.assign(n, vector<int>(n, 0));
    min_dist = INT_MAX;

    q.push({{a, b}, 0});
    visited[a][b] = 1;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if (min_dist < dist) break;
        if (arr[x][y] > shark_size) continue;
        if (arr[x][y] > 0 && arr[x][y] < shark_size) {
            min_dist = dist;
            eaten.push_back({x, y});
        }
        
        // shark_size보다 크면 못 먹음
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                if (arr[nx][ny] > shark_size) continue;
                visited[nx][ny] = 1;
                q.push({{nx, ny}, dist + 1});   
            }
        }
    }

    if (!eaten.empty()) {
        sort(eaten.begin(), eaten.end());
        return 1;
    }
    else return 0;

}

int main() {
    cin >> n;
    arr.resize(n, vector<int> (n,0));
    visited.resize(n, vector<int> (n, 0));

    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                x = i;
                y = j;
                arr[i][j] = 0;
            }
        }
    }

    while (1) {
        int found = bfs(x, y);
        if (!found) break;
        t += min_dist;
        x = eaten.front().first;
        y = eaten.front().second;
        arr[x][y] = 0;
        visited[x][y] = 0;
        eat++;
        if (eat == shark_size) {
            shark_size++;
            eat = 0;
        }
    }
    cout << t;

}