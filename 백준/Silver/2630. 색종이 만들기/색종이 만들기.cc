#include <iostream>
#include <algorithm>


using namespace std;
int map[129][129] = { 0, };

int blue = 0;
int white = 0;
void divide(int x, int y, int k);

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	divide(0, 0, n);
	cout << white << "\n" << blue;
}

void divide(int x, int y, int k) {
	int first = map[x][y];
	bool cut = false;
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (map[i][j] != first) {
				cut = true;
				break;
			}
		}
	}

	if (cut) {
		divide(x, y, k / 2);
		divide(x, y + k / 2, k / 2);
		divide(x + k / 2, y, k / 2);
		divide(x + k / 2, y + k / 2, k / 2);
	}
	else {
		if (first == 1) blue++;
		else white++;
	}
}