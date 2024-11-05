#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int n, m;
int arr1[MAX] = {0,};
int arr2[MAX] = {0,};
int visited[MAX] = {0,};

void dfs(int i) {
    if (i == m) {
        for (int j = 0; j < m; j++) {
            cout << arr2[j] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = 0;
    for (int j = 0; j < n; j++) {
        if (!visited[j] && prev != arr1[j]) {
            visited[j] = 1;
            arr2[i] = arr1[j];
            prev = arr1[j];
            dfs(i + 1);
            visited[j] = 0;
        }
    }
    
}

int main() {
    cin >> n >> m;
    for (int i = 0; i<n;i++) {
        cin >> arr1[i];
    }
    sort(arr1, arr1+n);
    dfs(0);
}