#include <iostream>
#include <queue>
#define MAX 1000001

using namespace std;

int dx[2]; bool ans = true;
int visited[MAX] = { 0, };
int f, s, g, u, d;
void bfs();

int main() {
	cin >> f >> s >> g >> u >> d;

	dx[0] = u; dx[1] = -d;
	bfs();

	if (ans == true) cout << "use the stairs";
	else cout << visited[g] - 1;
}

void bfs() {
	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty()) {
		s = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int nx = s + dx[i];

			if (nx > 0 && nx <= f) {
				if (visited[nx] == 0) {
					visited[nx] = visited[s]+1;
					q.push(nx);
				}
			}
			
			if (s == g) {
				ans = false;
				break;
			}
		}
	}
}