#include <iostream>
#include <queue>

using namespace std;

queue<pair <int, int> > q;
int visited[100001] = {0,};

int main() {
    int n, k;
    cin >> n >> k;
    q.push(pair <int, int> (n, 0));
    visited[n] = 1;

    while(!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (num == k) {
            cout << cnt;
            return 0;
        }
        
        if (!visited[num-1] && num - 1 >= 0 && num - 1 < 100001) {
            visited[num-1] = 1;
            q.push(pair<int, int> (num - 1, cnt + 1));
        }
        if (!visited[num+1] && num + 1 >= 0 && num + 1 < 100001) {
            visited[num+1] = 1;
            q.push(pair<int, int> (num + 1, cnt + 1));
        }
        if (!visited[num * 2] && num * 2 >= 0 && num * 2 < 100001) {
            visited[num*2] = 1;
            q.push(pair<int, int> (num * 2, cnt + 1));
        }
    }
}