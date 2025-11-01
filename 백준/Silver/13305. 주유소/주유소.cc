#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long len[100001] = { 0, }, price[100001] = { 0, }, min_price[100001];

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n - 1; i++) cin >> len[i];
	for (int i = 0; i < n; i++) cin >> price[i];
	
	min_price[0] = price[0];
	for (int i = 1; i < n; i++) {
		min_price[i] = min(min_price[i - 1], price[i]);
	}

	long long ans = 0;
	for (int i = 0; i < n - 1; i++) ans += len[i] * min_price[i];
	cout << ans;
}
