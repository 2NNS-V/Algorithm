#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <climits>

using namespace std;

int n, m;
int map[51][51] = {0,};
int visited[51][51] = {0,};

int da[4] = {0, -1, 0, 1};
int db[4] = {-1, 0, 1, 0};

int bfs(int x, int y) {
    queue<pair<int, int> > q;
    int room_size = 0;

    q.push(make_pair(x, y));
    visited[x][y] = 1;
    room_size++;

    while (!q.empty()) {
        int a = q.front().first; int b = q.front().second; 
        q.pop();

        int wall = 1;
        for (int i = 0; i < 4; i++) {
            if ((map[a][b] & wall) != wall) { // 벽이 없음
                int na = a + da[i]; int nb = b + db[i];
                if (na < 0 || na >= m || nb < 0 || nb >= n) {
                    wall <<= 1;
                    continue;
                }
                if (visited[na][nb]) {
                    wall <<= 1;
                    continue;
                }
                
                room_size++;
                visited[na][nb] = 1;
                q.push(make_pair(na, nb));
            }
            wall <<= 1;
        }
    }
    return room_size;
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }   

    int cnt = 0;
    int biggest = -INT_MAX;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                biggest = max(biggest, bfs(i,j));
                cnt++;
            }
        }
    }

    cout << cnt << endl << biggest << endl;

    // 벽 없앴을 때 큰 거 찾기
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int wall = 1; wall <= 8; wall <<= 1) {
                if ((wall & map[i][j]) == wall) {
                    memset(visited, 0, sizeof(visited));
                    map[i][j] -=  wall;
                    biggest = max(biggest, bfs(i, j));
                    map[i][j] +=  wall;
                }

            }
        }
    }

    cout << biggest ;
}