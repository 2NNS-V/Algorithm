#include <iostream>
#include <vector>

using namespace std;

int map[4][8] = {0,};

void input() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            char a; cin >> a;
            map[i][j] = a - '0';
        }
    }
}

void rotate(int n, int d) {
    if (d == -1) { // 반시계
        int tmp = map[n][0];
        for (int j = 0; j < 7; j++) {
            map[n][j] = map[n][j+1];
        }
        map[n][7] = tmp;
    }

    else if (d == 1) { // 시계
        int tmp = map[n][7];
        for (int j = 7; j >= 1; j--) {
            map[n][j] = map[n][j-1];
        }
        map[n][0] = tmp;
    }
}

void solution() {
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int n, d; 
        cin >> n >> d;
        n--;

        int dir[4] = {0, };
        dir[n] = d;

        for (int j = n - 1, t = -d; j >= 0; j--, t = -t) {
            if (map[j][2] == map[j+1][6]) break;
            dir[j] = t;
        }

        for (int j = n + 1, t = -d; j < 4; j++, t = -t) {
            if (map[j-1][2] == map[j][6]) break;
            dir[j] = t;
        }
        
        for (int i = 0; i < 4; i++) {
            rotate(i, dir[i]);
        }
    }

    int ans = 0;
    if (map[0][0]) ans += 1;
    if (map[1][0]) ans += 2;
    if (map[2][0]) ans += 4;
    if (map[3][0]) ans += 8;
    cout << ans;
}

int main() {
    input();
    solution();
    return 0;
}