#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n, h;
vector<vector<vector<int> > > arr;
queue<pair<pair<int, int>, int> > q;
queue<pair<pair<int, int>, int> > tmp;

int ans = 0;

// * 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

void bfs(int x, int y, int z) {
    for (int i = 0; i < 6; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h || arr[nx][ny][nz] != 0) continue; 

        if (arr[nx][ny][nz] == 0) { // * 익지 않음
            arr[nx][ny][nz] = 1;
            tmp.push(pair<pair<int,int>, int> ( pair<int, int> (nx,ny), nz) );
        }
    }
}

int main() {
    cin >> m >> n >> h;
    arr.resize(n, vector<vector<int> >(m, vector<int> (h)));

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) { // * 익은 토마토인 경우
                    q.push(pair<pair<int,int>, int> (pair<int, int> (i,j), k));
                }
            }
        }
    }

    while(!q.empty()) {
        bfs(q.front().first.first, q.front().first.second, q.front().second);
        q.pop();

        if (q.empty()) {
            ans++;
            while (!tmp.empty()) {
                q.push(pair<pair<int,int>, int> ( pair<int, int> (tmp.front().first.first, tmp.front().first.second), tmp.front().second));
                tmp.pop();
            }
        }
    }

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j][k] == 0) { // * 다 익지 않았음
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << ans - 1;
    return 0;
}