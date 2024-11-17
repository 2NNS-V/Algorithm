#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, cnt = 0;

vector<vector<int> > graph;
vector<vector<int> > tmp;


void bfs() {
    queue<pair<int, int> > q;
    tmp = graph;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (tmp[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && tmp[nx][ny] == 0) {
                            tmp[nx][ny] = 2;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }


    int tmp_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == 0) tmp_cnt++;
        }
    }

    if (cnt < tmp_cnt) cnt = tmp_cnt;
    
}

void search(int walls) {
    if (walls == 3) {
        bfs();
        return;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0) {
                graph[i][j] = 1;
                search(walls+1);
                graph[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    graph.resize(n, vector<int>(m,0));
    tmp.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){ 
            cin >> graph[i][j];
        }
    }

    search(0);
    cout << cnt << '\n';
    return 0;
    
}