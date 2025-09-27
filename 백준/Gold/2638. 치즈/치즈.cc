#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int n, m;
int map[101][101] = {0,};
int visited[101][101] = {0,};
int touch[101][101] = {0, };
vector<pair<int, int> > cand;
int t = 0;

int da[4] = {0, -1, 0, 1};
int db[4] = {-1, 0, 1, 0};
    
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
            // if (visited[na][nb]) continue;

            if (map[na][nb] == 0) {
                if (!visited[na][nb]) {
                    visited[na][nb] = 1;
                    q.push(make_pair(na, nb));
                }
            }
            else if (map[na][nb] == 1) {
                touch[na][nb]++;
                if (touch[na][nb] >= 2) {
                    cand.push_back(make_pair(na, nb));
                }
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
        memset(touch, 0, sizeof(touch));
        cand.clear();

        bfs(0,0);
        if (cand.size() == 0) {
            cout << t << endl; 
            break;
        }

        for (int i = 0; i < cand.size(); i++) {
            int x = cand[i].first; int y = cand[i].second;
            map[x][y] = 0;
        }
        t += 1;
    }
}