#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m, k;
vector<int> start_points;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y); 
    }

    start_points.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> start_points[i];
        start_points[i]--;
    }
    vector<int> worst(n, 0);          // 각 노드까지의 "최대" 거리
    vector<int> reachCount(n, 0);     // 몇 개의 시작점에서 도달 가능한지
 
    // 시작점 k개에서만 BFS  ->  O(k * (n + m))
    for (int s : start_points) {
        vector<int> dist(n, -1);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
 
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int next : adj[x]) {
                if (dist[next] != -1) continue;
                dist[next] = dist[x] + 1;
                q.push(next);
            }
        }
 
        for (int v = 0; v < n; v++) {
            if (dist[v] == -1) continue;
            reachCount[v]++;
            worst[v] = max(worst[v], dist[v]);
        }
    }
 
    int ans = INT_MAX;
    for (int v = 0; v < n; v++) {
        if (reachCount[v] == k)        // 모든 시작점에서 도달 가능한 후보만
            ans = min(ans, worst[v]);
    }
 
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
    return 0;
}