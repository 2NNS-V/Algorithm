#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> score(n), sum(n, 0);

    // 등수 계산 후 출력
    for (int c = 0; c < 3; c++) {
        vector<int> cnt(1002, 0);
        for (int i = 0; i < n; i++) {
            cin >> score[i];
            sum[i] += score[i];
            cnt[score[i]]++;
        }
        
        // cnt[v] = 점수가 v 이상인 사람 수
        for (int v = 1000; v >= 0; v--) cnt[v] += cnt[v + 1];
        for (int i = 0; i < n; i++)
            cout << cnt[score[i] + 1] + 1 << ' ';  
        cout << '\n';
    }

    vector<int> cnt(3002, 0);
    for (int i = 0; i < n; i++) cnt[sum[i]]++;
    for (int v = 3000; v >= 0; v--) cnt[v] += cnt[v + 1];
    for (int i = 0; i < n; i++)
        cout << cnt[sum[i] + 1] + 1 << ' ';
    cout << '\n';

    return 0;
}