#include <iostream>
#include <algorithm>

using namespace std;
int map[65][65];

void divide(int x, int y, int k);


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string S; cin >> S;
		for (int j = 0; j < S.length(); j++) {
			map[i][j] = S[j] - '0';
		}
	}

	divide(0, 0, n);
}

void divide(int x, int y, int k) {
	if (k == 1) {
		cout << map[x][y];
		return;
	}

	bool zero = true; bool one = true;

	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (map[i][j] == 1) zero = false;
			if (map[i][j] == 0) one = false;
		}
	}

	if (zero == true) {
		cout << 0;
		return;
	}
	if (one == true) {
		cout << 1;
		return;
	}

	cout << "(";
	divide(x, y, k / 2);
	divide(x, y + k / 2, k / 2);
	divide(x + k / 2, y, k / 2);
	divide(x + k / 2, y + k / 2, k / 2);
	cout << ")";

}