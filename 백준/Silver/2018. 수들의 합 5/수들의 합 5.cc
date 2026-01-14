#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n; cin >> n;
	set<set<int>> s;
	set<int> tmp; // 덧셈

	int start = 1, end = 1;
	int answer = 0, sum = 1;
	while (end <= n) {
		if (sum == n) {
			// n에 도달한 경우
			answer++;
			end++;
			sum += end;
		}
		
		else if (sum < n) {
			// answer이 n보다 작은 경우
			end++;
			sum += end;

		}
		else {
			sum -= start;
			start++;
		}
	}

	cout << answer;
	return 0;
}