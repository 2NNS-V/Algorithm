#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector <int>arr(n+1);

	int value;
	for (int i = 0; i < n; i++) {
		cin >> value;
		arr[i] = value;
	}

	// 1. 선택 절차
	// sort(arr.begin(), arr.end());

	// 2. 적절성 검사
	int sum = 0;
	for (int i = n - 1; i >= 0 ; i--) {
		sum += k / arr[i];
		k = k % arr[i];
	}

	// 3. 해답 검사
	cout << sum;
}

