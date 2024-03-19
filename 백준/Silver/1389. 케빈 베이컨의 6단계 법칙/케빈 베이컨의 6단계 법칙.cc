#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int n, m; 
void bfs(vector<vector<int>> graph, int a);
vector<int> ans(101, 0);
int sum[101] = {0,};

int main() {
    cin >> n >> m;
    vector<vector<int>> graph(101, vector<int>(101, 0));

    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        graph[a][b] = 1; graph[b][a] = 1;
    }

    for (int i = 1; i<=n;i++) {
        bfs(graph, i);
        sum[i] = accumulate(ans.begin(), ans.end(), 0);
        fill(ans.begin(), ans.end(), 0);
    }

    int min = sum[1]; int j = 1;
    for (int i =1 ;i<=n;i++) {
        if (sum[i] < min) {
            min = sum[i];
            j = i;
        }
    }
    cout << j << "\n";

}

int cnt = 0;
void bfs(vector<vector<int>> graph, int a) {
    queue<int> q;
    int visited[101] = {0,};
    q.push(a);
    visited[a] = 1;

    while(!q.empty()) {
        int i = q.front();
        q.pop();

        for (int j =1; j<=n;j++) {
            if (!visited[j] && graph[i][j] == 1) {
                q.push(j);
                visited[j] = 1;
                ans[j] = ans[i] + 1;
            }
        }
    }
}
