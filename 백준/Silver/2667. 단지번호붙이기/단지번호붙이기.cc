#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 26

using namespace std;

int graph[MAX][MAX] = { 0, }; // graph
int visited[MAX][MAX] = { 0, }; // 방문여부

vector<int> arr;
int n, cnt;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void bfs(int i, int j) {
    queue<pair <int, int>> q;
    q.push({ i,j });
    visited[i][j] = 1;
    int cnt = 0; cnt++;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (!visited[nx][ny] && graph[nx][ny] == 1) {
                    q.push({ nx, ny });
                    visited[nx][ny] = 1;
                    cnt++; // 1의 개수
                }
            }
        }
    }
    if (cnt) {
        arr.push_back(cnt);
    }

}


int main() {
    cin >> n;
    for (int i = 0;i < n; i++) {
        string s; cin >> s;
        for (int j = 0;j < n;j++) {
            graph[i][j] = s[j] - '0';
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (!visited[i][j] && graph[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    cout << arr.size() << "\n";
    sort(arr.begin(), arr.end());
    for (unsigned long int i = 0;i < arr.size();i++)
        cout << arr[i] << "\n";

    return 0;
}