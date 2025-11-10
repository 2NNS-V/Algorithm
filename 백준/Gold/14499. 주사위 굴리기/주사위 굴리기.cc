#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > arr;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dice[6] = {0, };

void move(int d) {
    if (d == 1) {
        int tmp = dice[0];

        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = tmp;
    }
    else if (d == 2) {
        int tmp = dice[0];

        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = tmp; 
    }
    else if (d == 3) {
        int tmp = dice[1];
        
        dice[1] = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[5];
        dice[5] = tmp;
    }
    else if (d == 4) {
        int tmp = dice[1];

        dice[1] = dice[5];
        dice[5] = dice[0];
        dice[0] = dice[4];
        dice[4] = tmp;
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n, vector<int> (m, 0));
    
    int x, y, k; cin >> x >> y >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int d; cin >> d;

        int nx = x + dx[d-1];
        int ny = y + dy[d-1];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

        move(d);
        if (arr[nx][ny] == 0) {
            // 주사위의 바닥면이 칸으로 복사
            arr[nx][ny] = dice[0];
        }
        else {
            // 칸의 수가 주사위 바닥면으로 복사
            // 칸의 수가 0으로 변경
            dice[0] = arr[nx][ny];
            arr[nx][ny] = 0;
        }

        // 이동할 때마다 주사위 윗면에 수 출력
        cout << dice[1] << endl;
        x = nx; y = ny;
    }
}