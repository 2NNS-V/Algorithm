#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(int x, int y) {
	return x > y;
}
int main() {
	int n, k;
	cin >> n;

	int a[51], b[51];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a, a+n);
	sort(b, b+n, cmp);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (a[i] * b[i]);
	}
	cout << ans;
}
