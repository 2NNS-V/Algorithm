#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

int trans(int dir) {
    dir++;
    if (dir == 9) dir = 1;
    return dir;
}

int dfs(vector<pair<pair<int, int>, int>>& arr, int sx, int sy, int sum) {
    int fish = -1;
    for (int i = 1; i < 17; i++) {
        if (arr[i].first.first == sx && arr[i].first.second == sy) {
            fish = i;
            break;
        }
    }
    if (fish < 0) return sum;

    sum += fish;
    int sdir = arr[fish].second;

    arr[fish] = {{-1, -1}, -1};
    arr[0] = {{sx, sy}, sdir};

    // 물고기 이동
    for (int i = 1; i < 17; i++) {
        if (arr[i].second == -1) continue;

        int x = arr[i].first.first;
        int y = arr[i].first.second;
        int dir = arr[i].second;

        int cnt = 0;
        while (cnt < 8) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 ||
                (nx == arr[0].first.first && ny == arr[0].first.second)) {
                dir = trans(dir);
                cnt++;
                continue;
            }

            int k = -1;
            for (int j = 1; j < 17; j++) {
                if (arr[j].first.first == nx && arr[j].first.second == ny) {
                    k = j;
                    break;
                }
            }

            arr[i].second = dir;
            if (k == -1) arr[i].first = {nx, ny};
            else swap(arr[i].first, arr[k].first);

            break;
        }
    }

    int maxValue = sum;
    bool canMove = false;

    for (int i = 1; i <= 3; i++) {
        int nx = sx + dx[sdir] * i;
        int ny = sy + dy[sdir] * i;

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;

        int targetFish = -1;
        for (int j = 1; j < 17; j++) {
            if (arr[j].first.first == nx && arr[j].first.second == ny) {
                targetFish = j;
                break;
            }
        }

        if (targetFish != -1) {
            canMove = true;
            vector<pair<pair<int, int>, int>> tmp(arr);
            maxValue = max(maxValue, dfs(tmp, nx, ny, sum));
        }
    }

    if (!canMove) return sum;
    return maxValue;
}

int main() {
    vector<pair<pair<int, int>, int>> base(17, {{0,0}, 0});

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;

            if (i == 0 && j == 0) {
                base[0] = {{i, j}, b};
            }
            base[a] = {{i, j}, b};
        }
    }

    cout << dfs(base, 0, 0, 0);
}