#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, K;
vector<vector<int>> grid;
int dp[300][300];

int dfs(int x, int y, int mid) {
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 1;
   
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            int diff = grid[nx][ny] - grid[x][y];

            if (diff > 0 && diff <= mid)
                dp[x][y] = max(dp[x][y], 1 + dfs(nx, ny, mid));
        }
    }
    return dp[x][y];   
}

int reach(int mid) {
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dfs(i, j, mid) >= K) return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> K;

    grid.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // 이분 탐색
    int low = 1, high = 100000000;
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (reach(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    if (ans != high) cout << ans;
    else cout << "-1";
    return 0;
}
