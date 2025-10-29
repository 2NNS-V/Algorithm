#include <iostream>

using namespace std;

int state[4][8];

void rotate(int n, int d) {
    if (d == -1) {
        int first = state[n][0];
        for (int i = 0; i < 7; i++) {
            state[n][i] = state[n][i+1];
        }
        state[n][7] = first;

    }
    else if (d == 1) {
        int last = state[n][7];
        for (int i = 7; i >= 1; i--) {
            state[n][i] = state[n][i-1];
        }
        state[n][0] = last;
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            char ch; cin >> ch;
            state[i][j] = ch - '0';
        }
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int num, dir;
        cin >> num >> dir;
        num--;

        int direction[4] = {0,};
        direction[num] = dir;

        for (int j = num - 1; j >= 0; j--) {
            if (state[j][2] == state[j+1][6]) break;
            direction[j] = -direction[j+1];
        }

        for (int j = num + 1; j < 8; j++) {
            if (state[j-1][2] == state[j][6]) break;
            direction[j] = -direction[j-1];
        }

        for (int j = 0; j < 4; j++) {
            rotate(j, direction[j]);
        }
    }

    int score = 0;
    int weights[4] = {1, 2, 4, 8};
    for (int i = 0; i < 4; i++) {
        if (state[i][0] == 1) {
            score += weights[i];
        }
    }
    cout << score;
}