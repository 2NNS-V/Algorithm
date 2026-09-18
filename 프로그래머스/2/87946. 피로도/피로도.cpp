#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> visited;
int MAX = 0;

void dfs(int k, int i, vector<vector<int>> dungeons, int cnt) {
    if (k < dungeons[i][0]) return;
    
    cnt++;
    visited[i] = 1;
    k -= dungeons[i][1];
    
    for (int j = 0; j < dungeons.size(); j++) {
        if (!visited[j] && k >= dungeons[j][0]) {
            dfs(k, j, dungeons, cnt);
        }
    }
    visited[i] = 0;
    if (MAX < cnt) MAX = cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    visited.resize(dungeons.size());
    
    for (int i = 0; i < dungeons.size(); i++) {
        dfs(k, i, dungeons, 0);
    }
    
    return MAX;
}