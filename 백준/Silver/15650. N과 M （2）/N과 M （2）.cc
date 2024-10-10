#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = {0,};


void dfs(int num, int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    else {
        for (int i = num; i <= n; i++) {
            arr[k] = i;
            dfs(i + 1, k + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(1, 0);
    
    return 0;
}