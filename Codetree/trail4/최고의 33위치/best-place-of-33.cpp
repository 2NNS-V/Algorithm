#include <iostream>
#include <climits>

using namespace std;

int N;
int grid[20][20];
int visited[20][20] = {0,};

int dfs(int a, int b) {
    int cnt = 0;
    for (int i = a; i < 3 + a; i++) {
        for (int j = b; j < 3 + b; j++) {
            if (grid[i][j] == 1) cnt++;
        }
    }
    
    return cnt;

}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int MAX = INT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            MAX = max(dfs(i, j), MAX);
        }
    }

    cout << MAX;
    return 0;
}
