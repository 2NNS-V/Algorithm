#include <iostream>
#include <vector>
#include <queue>
#include <utility>


#define INF 999999

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e, k; 
    cin >> n >> e >> k;

    
    vector<int> found(n+1, 0);
    vector<int> distance(n+1, INF);
    vector<vector<pair<int, int> > > weight(n + 1);

    for (int i = 1; i <= e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        weight[u].push_back({v, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, k}); 
    distance[k] = 0;

   while (!pq.empty()) {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist > distance[curr]) continue;

        for (auto &edge : weight[curr]) {
            int next = edge.first;
            int weight = edge.second;

            if (distance[next] > distance[curr] + weight) {
                distance[next] = distance[curr] + weight;
                pq.push({distance[next], next});
            }
        }
    }


    // 0에서부터 i까지 최단 경로 출력
    for (int i = 1; i <= n; i++) {
        if (distance[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", distance[i]);
        }
    }
    return 0;
}
