#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int map[101][101] = {0,};
int visited[101][101] = {0,};
vector<pair<int, int> > cand;
int n, m; // 판의 세로와 가로 크기
int melt = 0;
int t = 0;

int da[4] = {0, -1, 0, 1};
int db[4] = {-1, 0, 1, 0};

 // 녹을 치즈인지 판단 => 공기에서 치즈로 넘어가면 후보로 지정
// 후보를 전부 0으로 바꿔줌
// 녹은 개수 저장
// 후보가 비어있으면 종료 (걸린 시간(=사이클 수), 그 전에 녹은 개수 프린트)


void bfs(int x, int y) {
    queue<pair<int, int> > q;
    
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while (!q.empty()) {
        int a = q.front().first; int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int na = a + da[i]; int nb = b + db[i];
            if (na < 0 || na >= n || nb < 0 || nb >= m) continue;
            if (visited[na][nb]) continue;

            if (map[a][b] == 0 && map[na][nb] == 1) { 
                cand.push_back(make_pair(na, nb)); 
                visited[na][nb] = 1;
            }
            else if (map[na][nb] == 0) {
                q.push(make_pair(na, nb));
                visited[na][nb] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while (1) {
        memset(visited, 0, sizeof(visited));
        cand.clear();
        
        bfs(0, 0);
        if (cand.size() == 0) {
            cout << t << endl << melt;
            break;
        }

         for (int i = 0; i < cand.size(); i++) {
            int x = cand[i].first; int y = cand[i].second;
            map[x][y] = 0;
        }
        melt = cand.size();
        t += 1;
    }
}