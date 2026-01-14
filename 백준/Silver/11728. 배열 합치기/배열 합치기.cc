#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> arr(n + m, 0);
	for (int i = 0; i < n + m; i++) {
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n + m; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}