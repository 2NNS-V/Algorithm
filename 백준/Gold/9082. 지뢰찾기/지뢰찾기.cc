#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    int ans=0;
    while (t--) {
        int n;
        cin >> n;

        vector<int> cnt(n, 0);

        for (int j = 0; j < n; j++) {
            char tmp;   
            cin >> tmp;
            cnt[j] = tmp - '0';
        }


        string str;
        cin >> str;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (cnt[i] != 0 && cnt[i+1] != 0) {
                    cnt[i+1]--;
                    cnt[i]--;
                    ans++;
                }
                
            }
            else if (i == n - 1) {
                if (cnt[i] != 0 && cnt[i-1] != 0) {
                    cnt[i-1]--; 
                    cnt[i]--;
                    ans++;
                }
            }
            else {
                if (cnt[i] != 0 && cnt[i-1] != 0 && cnt[i+1] != 0) {
                    cnt[i]--;
                    cnt[i-1]--;
                    cnt[i+1]--;
                    ans++;
                }
            }
        }  

        cout << ans << endl;
    }
}   