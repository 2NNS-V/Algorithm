#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int H, W;

vector<vector<char>> grid;
vector<vector<int>> visited;

// 동, 남, 서, 북
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

char dirChar[4] = {'>', 'v', '<', '^'};

bool canMove(int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    int nnx = x + 2 * dx[dir];
    int nny = y + 2 * dy[dir];

    // 한 칸째 범위 확인
    if (nx < 0 || nx >= H || ny < 0 || ny >= W)
        return false;

    // 두 칸째 범위 확인
    if (nnx < 0 || nnx >= H || nny < 0 || nny >= W)
        return false;

    // 두 칸 모두 #이고 아직 방문하지 않았는지
    return grid[nx][ny] == '#' &&
           grid[nnx][nny] == '#' &&
           !visited[nx][ny] &&
           !visited[nnx][nny];
}


string dfs(int x, int y, int dir) {

    string ans;

    // 시작점 방문 처리
    visited[x][y] = 1;

    while (1) {

        // --------------------
        // 1. A로 갈 수 있는 경우
        // --------------------
        if (canMove(x, y, dir)) {

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            int nnx = x + 2 * dx[dir];
            int nny = y + 2 * dy[dir];

            visited[nx][ny] = 1;
            visited[nnx][nny] = 1;

            x = nnx;
            y = nny;

            ans += 'A';
        }

        // --------------------
        // 2. A가 안 되면 R
        // --------------------
        else {

            int right = (dir + 1) % 4;

            if (canMove(x, y, right)) {

                dir = right;

                ans += 'R';

                int nx = x + dx[dir];
                int ny = y + dy[dir];

                int nnx = x + 2 * dx[dir];
                int nny = y + 2 * dy[dir];

                visited[nx][ny] = 1;
                visited[nnx][nny] = 1;

                x = nnx;
                y = nny;

                ans += 'A';
            }

            // --------------------
            // 3. R도 안 되면 L
            // --------------------
            else {

                int left = (dir + 3) % 4;

                if (canMove(x, y, left)) {

                    dir = left;

                    ans += 'L';

                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    int nnx = x + 2 * dx[dir];
                    int nny = y + 2 * dy[dir];

                    visited[nx][ny] = 1;
                    visited[nnx][nny] = 1;

                    x = nnx;
                    y = nny;

                    ans += 'A';
                }

                else {
                    break;
                }
            }
        }
    }

    return ans;
}


int main() {

    cin >> H >> W;

    grid.resize(H, vector<char>(W));
    visited.resize(H, vector<int>(W));

    int total = 0;

    // 입력
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {

            cin >> grid[i][j];

            if (grid[i][j] == '#')
                total++;
        }
    }

    int bestX = -1;
    int bestY = -1;
    int bestDir = -1;

    string bestAns = "";

    // 모든 #을 시작점으로 시도
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {

            if (grid[i][j] != '#')
                continue;

            // 시작 방향 4개 전부 시도
            for (int dir = 0; dir < 4; dir++) {

                // 매번 방문 배열 초기화
                visited.assign(H, vector<int>(W, 0));

                // 시뮬레이션
                string ans = dfs(i, j, dir);

                // 방문한 #의 개수 계산
                int cnt = 0;

                for (int x = 0; x < H; x++) {
                    for (int y = 0; y < W; y++) {

                        if (visited[x][y])
                            cnt++;
                    }
                }

                // 모든 #을 방문한 경우
                if (cnt == total) {

                    bool isBetter = false;

                    if (bestDir == -1) {
                        isBetter = true;
                    }
                    else if (ans.length() < bestAns.length()) {
                        // 1순위: 명령어 개수
                        isBetter = true;
                    }
                    else if (ans.length() == bestAns.length()) {

                        if (i > bestX) {
                            // 2순위: 행 번호가 큰 것
                            isBetter = true;
                        }
                        else if (i == bestX && j > bestY) {
                            // 3순위: 열 번호가 큰 것
                            isBetter = true;
                        }
                    }

                    if (isBetter) {
                        bestX = i;
                        bestY = j;
                        bestDir = dir;
                        bestAns = ans;
                    }
                }
            }
        }
    }

    // 문제에서 좌표가 1-based라면 +1
    cout << bestX + 1 << " " << bestY + 1 << '\n';

    cout << dirChar[bestDir] << '\n';

    cout << bestAns << '\n';

    return 0;
}