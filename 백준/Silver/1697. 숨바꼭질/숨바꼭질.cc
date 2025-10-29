#include <iostream>
#include <queue>

using namespace std;

int n, k; 
int visited[100001] = {0,};

int main() {
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == k) break;

        int minus = cur - 1;
        int plus = cur + 1;
        int multi = cur * 2;

        if (minus >= 0 && !visited[minus]) {
            q.push(minus);
            visited[minus] = visited[cur] + 1;
        }

        if (plus < 100001 && !visited[plus]) {
            q.push(plus);
            visited[plus] = visited[cur] + 1;
        }

        if (multi < 100001 && !visited[multi]) {
            q.push(multi);
            visited[multi] = visited[cur] + 1;
        }

    }
    cout << visited[k];
}