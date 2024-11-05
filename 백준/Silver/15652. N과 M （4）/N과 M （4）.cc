#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = {0};
int visited[MAX] = {0};

void dfs(int num, int i) {
    if (i == m) {
        for (int j = 0; j < m; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
        return;
    }

    for (int j = num; j <= n; j++) {
        visited[j] = 1;
        arr[i] = j;
        dfs(j, i+1);
        visited[j] = 0;
    }

}


int main() {
    cin >> n >> m;

    dfs(1,0);
}
