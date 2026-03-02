#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, m, k;
int t = 0;

// 상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct MOVE {
    int x, y, dir; 
};

struct SMELL {
    int id = -1;
    int t = 0;
};

SMELL map[21][21]; // id와 t 저장
vector<vector<int>> prefer; // 우선순위
vector<MOVE> shark; // 현재 위치, 방향 저장
vector<int> out_list; // out 여부 저장
int check;

void input() {
    cin >> n >> m >> k;

    shark.resize(m);
    prefer.resize(m * 4, vector<int> (4, 0));
    out_list.resize(m, 0);
    check = m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int p; cin >> p;
            if (p != 0) {
                map[i][j].id = p-1;
                map[i][j].t = k;
                shark[p-1].x = i;
                shark[p-1].y = j;
            }
        }
    }

    // 상어의 현재 방향 저장
    for (int i = 0; i < m; i++) {
        int dir; cin >> dir; // 1 ~ 4
        shark[i].dir = dir - 1;  // 0 ~ 3
    }

    // 상어의 우선순위 저장
    for (int i = 0; i < m * 4; i++) {
        for (int j = 0; j < 4; j++) {
            // i번째 상어의 우선순위 4개
            int tmp; cin >> tmp;
            prefer[i][j] = tmp - 1;
        }
    }
}

MOVE move_shark(int num) {
    // TODO: 주변 빈칸 찾기 
    int x = shark[num].x;
    int y = shark[num].y;
    int dir = shark[num].dir; 

    for (int i = 0; i < 4; i++) {
        int next_dir = prefer[(num * 4) + dir][i];
        int nx = dx[next_dir] + x;
        int ny = dy[next_dir] + y;

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (map[nx][ny].t == 0) { // 빈칸 찾음
                return {nx, ny, next_dir};
            }
        }
    }
    
    // 빈 칸을 못 찾은 경우 자기 자신 방향이 있는 곳으로 향함.
    for (int i = 0; i < 4; i++) {
        int next_dir = prefer[(num * 4) + dir][i];
        int nx = dx[next_dir] + x;
        int ny = dy[next_dir] + y;

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (map[nx][ny].id == num) { // 빈칸 찾음
                return {nx, ny, next_dir};
            }
        }
    }

    return {x, y, dir};
}

void solution() {
    if (check == 1) {
        cout << 0;
        return;
    }

    while (t < 1000) {
        t++;

        // 1만 남을 때까지 반복
        vector<MOVE> next_move(m);

        // 상어 위치 결정
        for (int i = 0; i < m; i++) {
            if (out_list[i]) continue;
            next_move[i] = move_shark(i);
        }

        // 냄새 제거
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j].t > 0) {
                    map[i][j].t--;
                    if (map[i][j].t == 0) map[i][j].id = -1;
                }
            }
        }

        // 상어 이동
        for (int i = 0; i < m; i++) {
            if (out_list[i]) continue;

            int nx = next_move[i].x;
            int ny = next_move[i].y;
            int nd = next_move[i].dir;

            if (map[nx][ny].t == k && map[nx][ny].id != -1) { 
                if (map[nx][ny].id < i) { // 그 상어가 나보다 번호가 작으면 내가 나감
                    out_list[i] = 1;
                    check--;
                }
            }
            else {
                shark[i] = {nx, ny, nd};
                map[nx][ny].id = i;
                map[nx][ny].t = k;
            }
        }

        if (check == 1) {
            cout << t;
            return;
        }
    }
    cout << -1;
}

int main() {
    input();
    solution();
    return 0;
}