#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

vector<int> adjacent[100];
int visited[101] = {0, };

void dfs(int x) {
    for (int i = 0; i < (int)adjacent[x].size(); i++) {
        if (!visited[adjacent[x][i]]) {
            visited[adjacent[x][i]] = 1;
            dfs(adjacent[x][i]);
        }
    }
}

int main() {
    int n, a;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            cin >> a;
            if (a) adjacent[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i);
        for (int j = 0; j < n; j++) {
            cout << visited[j] << " ";
        }
        cout << endl;
    }
}