#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int> > q;
queue<pair<int, int> > tmp;
vector<vector<int> > arr;

int m, n;
int ans = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    for (int i  = 0 ; i< 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
            arr[nx][ny] = 1;
            tmp.push(pair<int, int> (nx, ny));
        }
    }
}

int main() {
    cin >> m >> n;
    arr.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push(pair <int, int> (i, j));
            }
        }
    }

    while (!q.empty()) {
        bfs(q.front().first, q.front().second);
        q.pop();
        
        if (q.empty()) {
            ans++;
            while (!tmp.empty()) {
                q.push(pair<int, int> (tmp.front().first, tmp.front().second));
                tmp.pop();
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans - 1 ;
    return 0;
}