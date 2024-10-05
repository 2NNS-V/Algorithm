#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    while (arr.size() > 1) {
        arr[arr.size() - 2] += arr[arr.size() - 1];
        arr[0]--;
        cnt++;
        arr.pop_back();

        if (arr[0] == 0) {
            for (int i =0; i < arr.size(); i++) {
                arr[i] = arr[i+1];
            }
            arr.pop_back();
        }
    }
    cout << cnt;

    return 0;

}