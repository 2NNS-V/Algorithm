#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


int board[52][52];
bool check[52][52];


int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int sum = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M,r,c,d;
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	while (1) {
		if (check[r][c] == false) {			
			check[r][c] = true;
			sum++;			
		}
		bool ch = false;
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;
			int nx = r + dx[d];
			int ny = c + dy[d];
			if (board[nx][ny] == 0 && check[nx][ny] == false) {
				r += dx[d];
				c += dy[d];
				ch = true;
				break;
			}
		}
		if (!ch) { 
			int back = (d + 2) % 4; 
			if (board[r + dx[back]][c + dy[back]] == 1) break;
			r += dx[back];
			c += dy[back];
		}
	}
	cout << sum << "\n";
}