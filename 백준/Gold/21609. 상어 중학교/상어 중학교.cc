#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef struct {
    int size;
    int rainbow;
    int x;
    int y;
    vector<pair<int,int>> cells;
} BLOCK;

int n, m;
int score = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> arr;
vector<vector<int>> visited;
vector<BLOCK> group;

void input() {
    cin >> n >> m; // 한변의 크기, 색상의 수
    arr.resize(n, vector<int>(n, 0));
    visited.resize(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}

bool compare(const BLOCK&a, const BLOCK& b) {
    if (a.size != b.size) return a.size > b.size;
    if (a.rainbow != b.rainbow) return a.rainbow > b.rainbow;
    if (a.x != b.x) return a.x > b.x;
    return a.y > b.y;
}

BLOCK dfs(int x, int y, int color) {
    int min_x = (arr[x][y] == 0) ? 99 : x, min_y = (arr[x][y] == 0) ? 99 : y;
    int rainbow = (arr[x][y] == 0) ? 1 : 0;
    int size = 1;
    visited[x][y] = 1;

    vector<pair<int,int>> cells;
    cells.push_back({x,y});

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
            if (arr[nx][ny] == color || arr[nx][ny] == 0) {
                BLOCK child = dfs(nx, ny, color);

                size += child.size;
                rainbow += child.rainbow;
                cells.insert(cells.end(), child.cells.begin(), child.cells.end());
                
                if (child.x != 99) {
                    if (child.x < min_x || (child.x == min_x && child.y < min_y)) {
                        min_x = child.x;
                        min_y = child.y;
                    }
                }
                
            }
        }
    }
    return {size, rainbow, min_x, min_y, cells};
}

int search() {
    // TODO: 가장 큰 블록 그룹 찾기
    // 조건: 일반블럭의 색이 동일 + 검은색 블록 미포함 + 블럭의 개수가 2보다 큼
    group.clear();
    visited.assign(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] >= 1 && arr[i][j] <= m && !visited[i][j]) {
                BLOCK block = dfs(i, j, arr[i][j]);
                if (block.size >= 2) group.push_back(block);

                for (auto &p : block.cells) {
                    if (arr[p.first][p.second] == 0)
                        visited[p.first][p.second] = 0;
                }
            }
        }
    }

    if (group.empty()) return 0; 
    sort(group.begin(), group.end(), compare);
    
    BLOCK best = group[0];
    score += best.size * best.size;
    for (auto &p : best.cells)
        arr[p.first][p.second] = -2;
    return 1;
}


void gravity() {
    // TODO: 격자에 중력이 작용
    // 규칙: 검은색 블록을 제외한 모든 블럭이 행의 번호가 큰 칸으로 이동
    for (int i = 0; i < n; i++) {
        int x = n - 1;
        // 밑에서부터 찾기(어디서부터 중력을 작용하면 되는지 확인)
        for (int j = n - 1; j >= 0; j--) {
            if (arr[j][i] == -1) {
                x = j - 1;
            }

            else if (arr[j][i] >= 0) {
                if (j != x) {
                    arr[x][i] = arr[j][i];
                    arr[j][i] = -2;
                }
                x--;
            }
        }
    }

    
}

void rotate() {
    // TODO: 배열이 90도 반시계 회전
    vector<vector<int>> tmp(n, vector<int> (n , 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[n - j - 1][i] = arr[i][j];
        }
    }

    arr = tmp;
}



int main() {
    input();
    while (1) {
        if (!search()) break;
        gravity();
        rotate();
        gravity();
    }
    
    cout << score;
    
}