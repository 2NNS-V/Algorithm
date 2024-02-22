#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
	int n; cin >> n;
	int arr[51];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr+n);
	int ans = arr[0] * arr[n - 1];
	cout << ans;
}

