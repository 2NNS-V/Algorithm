#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;
int n, k, l;
int graph[102][102] = {0,}; // 사과 위치 저장
int visited[102][102] = {0,};
deque<pair <int, char> > turns;

// 북 동 남 서
int dx[] = {-1, 0 , 1, 0}; 
int dy[] = {0, 1, 0, -1};

void bfs(int a, int b);
int turn(char c, int cur_dir);

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1; // 사과 위치 저장
    }

    cin >> l; 
    for (int i=0;i<l;i++) {
        int second; char direction;
        cin >> second >> direction;
        turns.push_back(make_pair(second, direction));
    }

    bfs(1, 1);
    return 0;
}

int turn(char c, int dir_index) {
    if (c == 'L') return (dir_index + 3) % 4;
    else if (c == 'D') return (dir_index + 1) % 4;
}

void bfs(int a, int b) {
    deque<pair <int, int> > q;

    int t = 1; // 시간
    int dir_index = 1; // 방향 인덱스(오른쪽)
    int x = a, y = b;
    q.push_back(make_pair(x, y));

    while (1) {
        int nx = dx[dir_index] + x;
        int ny = dy[dir_index] + y;
    
        if (nx < 1 || ny < 1 || nx > n || ny > n || visited[nx][ny] == 1) {
            cout << t;
            break;
        }

        q.push_back(make_pair(nx, ny));
        visited[nx][ny] = 1;

        if (graph[nx][ny] == 1) { // 사과 있다
            graph[nx][ny] = 0;            
        }       
        
        else if (graph[nx][ny] == 0) { // 사과 없다
            visited[q.front().first][q.front().second] = 0;
            q.pop_front(); 
        }


        if (t == turns.front().first && !turns.empty()) { // x초 이후에 방향 회전
            dir_index = turn(turns.front().second, dir_index);
            turns.pop_front();
        }
        
        x = nx; y = ny;
        t++;
    }
}