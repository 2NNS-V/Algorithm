#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int graph[100001] = {0,}; // graph
int visited[100001]= {0,}; // 방문
int complete[100001] = {0,}; // 팀 빌딩 완료
int n, cnt;


void dfs(int node) {
    visited[node] = 1;
    int next = graph[node];

    if (!visited[next]) dfs(next);
    else if (!complete[next]) {
        for (int i = next; i!=node;i=graph[i]) {
            cnt++;
        }
        cnt++;
    }
    complete[node] = 1;
}

int main() {
    int t; cin >> t;
    for (int i=0;i<t;i++) {
        cin >> n;   

        memset(complete, 0 ,sizeof(complete));
        memset(visited, 0 , sizeof(visited));
        memset(graph, 0, sizeof(graph));

        for (int j = 1;j<=n;j++ ){
            cin >> graph[j];
        }

        cnt = 0;
        for (int k =1; k<=n;k++) {
            if (!visited[k]) dfs(k);
        }

        cout << n - cnt << "\n";
    }
}