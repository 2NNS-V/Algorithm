#include <iostream>
#include <vector>
#include <queue>
#include <cstring> 

using namespace std;

queue<pair<int, int> > q;
vector<vector<int> > arr;
int tmp[300][300] = {0,};
int visited[300][300] = {0,};

int n, m;
int ans = 0; // * 몇 년만에 두 덩이로 분리되는지

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    q.push(pair<int, int>(x, y));

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != 0 && visited[nx][ny] == 0) {
                q.push(pair<int, int> (nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }
}

void melt() {
    memset(tmp, 0, sizeof(tmp));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {   
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
                        cnt++;
                    }
                }
                int value = arr[i][j] - cnt;
                if (value > 0) tmp[i][j] = value;
            }
        }
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n, vector<int> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    

    // * 몇 덩이인지 확인하고 두 덩이이면 ans 출력
    while (1) {
        memset(visited, 0, sizeof(visited));
        int component = 0; // * 몇 덩이

        for (int i = 0; i < n; i++) {
            for (int j =0; j<m; j++) {
                if (visited[i][j] == 0 && arr[i][j]!= 0) {
                    component++;
                    bfs(i, j);
                }
            }
        }

        if (component == 0) {
            cout << 0 << endl;
            break;
        }
        else if (component >= 2) {
            cout << ans << endl;
            break;
        }

        ans++;
        melt();
    }
}