#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

struct moves {
    int x;
    int y;
};

int t,n;

moves home;
moves store[101];
moves festival;

queue<pair<int, int> > q;
int visited[101] = {0,};
bool ans;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (abs(festival.x - x) + abs(festival.y - y) <= 1000) {
            ans = true;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) continue;

            if (abs(store[i].x - x) + abs(store[i].y - y) <= 1000) {
                visited[i] = 1;
                q.push(pair<int, int> (store[i].x, store[i].y));
            }
        }
    }
    ans = false;
}

int main() {
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> home.x >> home.y;

        for (int k = 0; k < n; k++) {
            cin >> store[k].x >> store[k].y;
        }

        cin >> festival.x >> festival.y;
        
        while (!q.empty()) q.pop();
        fill(visited, visited + n, 0);
        ans = false;

        q.push(pair<int, int> (home.x, home.y));
        bfs();

        if (ans) cout << "happy" << endl;
        else cout << "sad" << endl;
    }
}