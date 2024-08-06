#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 16
#define INF  1000000000

using namespace std;

int w[MAX][MAX] = {0,};
int dp[1 << MAX][MAX] = {0};
int n;

int tsp(int visited, int current) {
     if (visited == (1 << n) - 1) {
        return w[current][0] != 0 ? w[current][0] : INF;
    }
    
    if (dp[visited][current] != -1) {
        return dp[visited][current];
    }

    int& ret = dp[visited][current];
    ret = INF;

    for (int next = 0; next < n; next++) {
        if (!(visited & (1 << next)) && w[current][next] != 0) {
            int newVisited = visited | (1 << next);
            dp[visited][current] = min(dp[visited][current], 
                                       w[current][next] + tsp(newVisited, next));
        }
    }

    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << tsp(1, 0) << endl;
    return 0;
}