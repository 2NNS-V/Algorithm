#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        
        vector<int> ans(s.length(), 0);
        int result = 0;
        if (s[0] == 'O') {
            ans[0] = 1;
            result++;
        }

        int j;
        for (j = 1; j <= s.length(); j++) {
            if (s[j] == 'O') {
                ans[j] = ans[j-1] + 1;
                result += ans[j];
            }

            else if (s[j] == 'X') {
                ans[j] = 0;
            }
        }
        cout << result << endl;
    }
    

}