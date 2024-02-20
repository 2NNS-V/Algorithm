#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string S;
	cin >> S;

	int ans = 0;
	string num;
	bool isMinus = false;

	for (int i = 0; i <= S.size(); i++) {
		if (S[i] == '-' || S[i] == '+' || i == S.size()) {
			if (isMinus) {
				ans -= stoi(num);
				num = "";
			}
			else {
				ans += stoi(num);
				num = "";
			}
		}
		else {
			num += S[i];
		}

		if (S[i] == '-') isMinus = true;
	}

	cout << ans;
}
