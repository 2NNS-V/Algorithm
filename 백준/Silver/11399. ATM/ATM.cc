#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, p;
	cin >> n;

	// 1 2 3 3 4
	// 1 3 6 9 13 => 32

	vector <int>arr(n+1);

	for (int i = 0; i < n; i++) {
		cin >> p;
		arr[i] = p;
	}

	// 1. 선택 절차 1 2 3 3 4
	sort(arr.begin(), arr.end());
	
	// 2. 적절성 검사
	int sum = 0;
	int ans = 0;
	for (int i = 2; i <= arr.size(); i++) {
		sum += arr[i-1];
		ans += sum;
	}

	// 3. 해답 검사
	
	cout << ans;
	
}