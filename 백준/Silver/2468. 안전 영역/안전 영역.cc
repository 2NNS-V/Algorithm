#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reset();
void dfs(int x, int y);

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int n;
int arr[101][101]; int map[101][101];
int visited[101][101] = { 0, };
int cnt = 0;
vector<int>ans;

int main() {
	 cin >> n;
	 int maxheight = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (maxheight < arr[i][j]) maxheight = arr[i][j];
		}
	}
	
	for (int h = 1; h <= maxheight; h++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] < h) map[i][j] = 0;
				else map[i][j] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0 && map[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		ans.push_back(cnt);

		reset();
	}
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1];
}


void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (map[nx][ny] && !visited[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 0; visited[i][j] = 0;
		}
	}
	cnt = 0;
}