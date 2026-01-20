#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    int x; cin >> x; // arr[i] + arr[j] = x를 만족하는 쌍의 수 구하기(i < j)

    int start = 0, end = n - 1;
    int cnt = 0;
    while (start < end) {
        int sum = arr[start] + arr[end];
        
        if (sum == x) {
            start++;
            end--;
            cnt++;
        }
        else if (sum < x) {
            start++;
        }
        else {
            end--;
        }
    }
    cout << cnt;
}