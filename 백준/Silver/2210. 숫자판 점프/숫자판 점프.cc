#include <iostream>
using namespace std;
#define MAX 5

int visited[1000000] = { 0 };
int arr[MAX][MAX];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int ans = 0;

void dfs(int x, int y, int n, int sum);

int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> arr[i][j];
		}
	}

	// 랜덤 수 지정(x, y)
	int n = 0; // 횟수
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dfs(i, j, n, arr[i][j]);
		}
	}

	cout << ans << endl;
}

void dfs(int x, int y, int n, int sum) {
	if (n == 5) {
		if (visited[sum] == false) {
			visited[sum] = true;
			ans++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < MAX && ny < MAX) {
			dfs(nx, ny, n + 1, sum * 10 + arr[nx][ny]);
		}
	}

}