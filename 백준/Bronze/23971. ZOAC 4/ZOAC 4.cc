#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double h, w, n, m;
	cin >> h >> w >> n >> m;
	cout << (long long)ceil(h / (n+1)) * (long long)ceil(w / (m+1));
}