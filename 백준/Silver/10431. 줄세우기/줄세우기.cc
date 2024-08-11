#include <iostream>
#include <vector>

using namespace std;

int main(){
    int p, num, t;
    cin >> p;

    for (int i = 0; i < p; i++) {
        int cnt = 0;
        vector<int>arr;

        cin >> t;
        cin >> num;
        arr.push_back(num);
        
        for (int j = 1; j < 20; j++) {
            int minValue = -1;
            cin >> num;

            for (int k = arr.size() -1; k >= 0; k--) {
                if (num < arr[k]) {
                    minValue = k;
                }
            }
            if (minValue == -1) arr.push_back(num);
            else {
                cnt += arr.size() - minValue;
                arr.insert(arr.begin() + minValue, num);
            }
        }

        cout << t << " " << cnt << "\n";
    }
    return 0;
}