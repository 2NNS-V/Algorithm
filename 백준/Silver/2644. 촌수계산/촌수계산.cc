#include <iostream>
using namespace std;

#define MAX 101
void dfs(int x, int cnt);

bool visited[MAX];
int arr[MAX][MAX];
int n, ans = -1;
int x, y, a, b, m;;

int main() {
	cin >> n >> a >> b >> m;

	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	dfs(a, 0);

	cout << ans;
	return 0;
}

void dfs(int x, int cnt) {
	visited[x] = 1;

	if (x == b) {
		ans = cnt;
		return;
	}

	for (int i = 1; i <= n; i++) {	
		if (!visited[i] && arr[x][i]) {
			dfs(i, cnt+1);
		}
	}
}