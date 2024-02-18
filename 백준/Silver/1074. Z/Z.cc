#include <iostream>
#include <cmath>

using namespace std;

void divide(int x, int y, int k);
int ans = 0;

int n, r, c;
int main() {
	cin >> n >> r >> c;
	divide(0, 0, pow(2, n));
}

void divide(int x, int y, int k) {
	if (c == x && r == y) {
		cout << ans;
		return;
	}

	else if (c < x + k && r < y + k && c >= x && r >= y) {
		divide(x, y, k/2);
		divide(x + k / 2, y, k / 2);
		divide(x, y + k / 2, k / 2);
		divide(x + k / 2, y + k / 2, k / 2);
	}

	else {
		ans += k * k;
	}

}