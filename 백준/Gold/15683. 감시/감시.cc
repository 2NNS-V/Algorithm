#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int n, m, k;
vector<vector<int> > arr;
vector<pair<int, int> > cctv;
int ans = INT_MAX;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int dir) {
    dir %= 4;
    while (1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        x = nx; y = ny;

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
        if (arr[nx][ny] == 6) return;
        if (arr[nx][ny] != 0) continue;
        arr[nx][ny] = -1;
    }
}

void monitor(int idx) { // 방향도 고려

    if (idx == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!arr[i][j]) cnt++;
            }
        }
        ans = min(cnt, ans);
        return;
    }

    int x = cctv[idx].first; int y = cctv[idx].second;
    int tmp[9][9];
    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = arr[i][j];
            }
        }

        if (arr[x][y] == 1)
            dfs(x, y, dir);
        else if (arr[x][y] == 2) {
            dfs(x, y, dir);
            dfs(x, y, dir + 2);
        }
        else if (arr[x][y] == 3) {
            dfs(x, y, dir);
            dfs(x, y, dir + 1);
        }
        else if (arr[x][y] == 4) {
            dfs(x, y, dir);
            dfs(x, y, dir + 1);
            dfs(x, y, dir + 2);
        } 
        else if (arr[x][y] == 5) {
            dfs(x, y, dir);
            dfs(x, y, dir + 1);
            dfs(x, y, dir + 2);
            dfs(x, y, dir + 3);
        }

        monitor(idx + 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = tmp[i][j];
            }
        }
    }
    
}

int main() {
    cin >> n >> m;
    arr.resize(n, vector<int> (m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j]; // 0: 빈칸, 1 ~ 5: CCTV 번호
            if (arr[i][j] != 0 && arr[i][j] != 6) 
                cctv.push_back(make_pair(i, j));
        }
    }

    monitor(0);

    // 사각지대의 최소 크기 출력
    cout << ans;

}