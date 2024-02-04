#include <iostream>
#include <vector>
using namespace std;

vector<vector <int>> v;

int main() {
	int r, c, q;
	cin >> r >> c >> q;

	v = vector<vector<int>>(r + 1, vector<int>(c + 1));
	vector<vector<int>> bright(r + 1, vector<int>(c + 1, 0));

	for (int i = 1;i <= r;i++) {
		int sum = 0;
		for (int j = 1; j <= c;j++) {
			cin >> v[i][j]; // 밝기
			sum += v[i][j];

			bright[i][j] = bright[i - 1][j] + sum;
		}
	}

	for (int i = 0;i < q;i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		int ans = bright[r2][c2] - bright[r1 - 1][c2] - bright[r2][c1 - 1] + bright[r1 - 1][c1 - 1];
		int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
		cout << ans / cnt << "\n";
	}
}