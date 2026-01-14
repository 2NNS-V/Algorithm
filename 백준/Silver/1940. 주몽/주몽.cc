#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	// 재료의 번호를 합쳐서 m이 되면 갑옷 만들어짐
	int m, n; cin >> n >> m; // 재료 개수
	vector<int> cloth(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> cloth[i];
	}

	sort(cloth.begin(), cloth.end());

	int ans = 0;
	int start = 0, end = n - 1, sum = 0;
	while (start < end) {
		int sum = cloth[start] + cloth[end];

		if (sum == m) {
			ans++;
			start++;
			end--;
		}
		else if (sum < m) {
			start++;
		}
		else if (sum > m) {
			end--;
		}
	}

	cout << ans;
	return 0;
}