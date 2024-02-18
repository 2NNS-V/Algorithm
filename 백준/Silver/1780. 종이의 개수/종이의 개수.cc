#include <iostream>
#include <algorithm>

using namespace std;
int map[2188][2188];

void divide(int x, int y, int k);
bool isSame;
int Zero = 0, One = 0, MinusOne = 0;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	divide(0, 0, n);

	cout << MinusOne << "\n" << Zero << "\n" << One;
}

void divide(int x, int y, int k) {
	isSame = true;

	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (map[i][j] != map[x][y]) {
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}

	if (!isSame) {
		divide(x, y, k / 3);
		divide(x, y + k / 3, k / 3);
		divide(x, y + (k / 3) * 2, k / 3);

		divide(x + k / 3, y, k / 3);
		divide(x + k / 3, y + k / 3, k / 3);
		divide(x + k / 3, y + (k / 3) * 2, k / 3);

		divide(x + (k / 3) * 2, y, k / 3);
		divide(x + (k / 3) * 2, y + k / 3, k / 3);
		divide(x + (k / 3) * 2, y + (k / 3) * 2, k / 3);
	}
	else {
		if (map[x][y] == 1) One++;
		else if (map[x][y] == 0) Zero++;
		else MinusOne++;
	}

}