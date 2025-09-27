#include <iostream>
#include <vector>

using namespace std;

int visited[101][101] = {0,};
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, d, g;  // 시작점(x,y), 시작방향(d), 세대(g)
        cin >> x >> y >> d >> g;
        
        vector<int> dir;
        dir.push_back(d);
        
        for (int j = 1; j <= g; j++) {
            for (int k = (int)dir.size() - 1; k >= 0; k--) {
                dir.push_back((dir[k] + 1) % 4);
            }
        }

        visited[x][y] = true;
        int cx = x; int cy = y;
        for (int j = 0; j < dir.size(); j++) {
            cx += dx[dir[j]]; cy += dy[dir[j]];
            if (0 <= cx && cx <= 100 && cy >= 0 && cy <= 100) visited[cx][cy] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (visited[i][j] && visited[i][j+1] && visited[i+1][j] && visited[i+1][j+1]) ans++;
        }
    }

    cout << ans;
}